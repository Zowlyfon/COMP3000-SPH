// Fill out your copyright notice in the Description page of Project Settings.


#include "SPHController.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraDataInterfaceArrayFloat.h"

// Sets default values
ASPHController::ASPHController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));

	RootComponent = NiagaraComponent;
}

void ASPHController::StartSimulation()
{
	Params.Domain = FVectorToFloat3(DomainBox->BoxExtents);
	NumP = (SpawnBox->BoxExtents.X / Params.H) * (SpawnBox->BoxExtents.Y / Params.H) * (SpawnBox->BoxExtents.Z / Params.H);
	NumCells = ((Params.Domain.x / Params.H) + 1) * ((Params.Domain.y / Params.H) + 1) * ((Params.Domain.z / Params.H) + 1);
	P = AllocateMemory(NumP, NumCells);

	NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);
	NiagaraComponent->ResetSystem();

	
	//InitSph(Params, P, make_float3(SpawnBox->BoxStart.X, SpawnBox->BoxStart.Y, SpawnBox->BoxStart.Z), make_float3(SpawnBox->BoxEnd.X, SpawnBox->BoxEnd.Y, SpawnBox->BoxEnd.Z));
	InitSph(Params, P, FVectorToFloat3(SpawnBox->BoxTransform - (SpawnBox->BoxExtents / 2.0f)), FVectorToFloat3(SpawnBox->BoxTransform + (SpawnBox->BoxExtents / 2.0f)));
	PutParticlesInCells(Params, P);
	FirstStep(Params, P);

	NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);

	SimShouldTick = true;
	SimStarted = true;

	SpawnBox->SetActorHiddenInGame(true);
}

void ASPHController::StopSimulation()
{
	PauseSimulation();
	SimStarted = false;
	FreeMemory(P);
	SpawnBox->SetActorHiddenInGame(false);
}

void ASPHController::PauseSimulation()
{
	SimShouldTick = false;
}

void ASPHController::UnpauseSimulation()
{
	SimShouldTick = true;
}

void ASPHController::SetParticleMass(float NewMass)
{
	Params.Mass = NewMass;
}

float ASPHController::GetParticleMass()
{
	return Params.Mass;
}

void ASPHController::SetViscosity(float NewViscosity)
{
	Params.Visc = NewViscosity;
}

float ASPHController::GetViscosity()
{
	return Params.Visc;
}

void ASPHController::SetRestDensity(float NewRestDensity)
{
	Params.RestDensity = NewRestDensity;
}

float ASPHController::GetRestDensity()
{
	return Params.RestDensity;
}

void ASPHController::SetGasConstant(float NewGasConstant)
{
	Params.GasConst = NewGasConstant;
}

float ASPHController::GetGasConstant()
{
	return Params.GasConst;
}

void ASPHController::SetGravityScale(float NewGravityScale)
{
	Params.G.z = NewGravityScale * -9.8;
}

float ASPHController::GetGravityScale()
{
	return Params.G.z / -9.8;
}

void ASPHController::SetH(float newH)
{
	Params.H = newH;
}

float ASPHController::GetH()
{
	return Params.H;
}

void ASPHController::SetDomainBoxExtents(FVector Extents)
{
	DomainBox->BoxExtents = Extents;
	DomainBox->BoxTransform = Extents / 2.0f;
}

FVector ASPHController::GetDomainBoxExtents()
{
	return DomainBox->BoxExtents;
}

void ASPHController::SetSpawnBoxExtents(FVector Extents)
{
	/*
	FBox NewBox = FBox(SpawnBox->BoxTransform - (Extents / 2.0f), SpawnBox->BoxTransform + (Extents / 2.0f));
	FBox DomainFBox = DomainBox->ToFBox();
	if (NewBox.IsInside(DomainFBox))
	{
		SpawnBox->BoxExtents = Extents;
	}
	*/
	SpawnBox->BoxExtents = Extents;
}

FVector ASPHController::GetSpawnBoxExtents()
{
	return SpawnBox->BoxExtents;
}

void ASPHController::SetSpawnBoxTransform(FVector Transform)
{
	/*
	FBox NewBox = FBox(Transform - (SpawnBox->BoxExtents / 2.0f), Transform + (SpawnBox->BoxExtents / 2.0f));
	FBox DomainFBox = DomainBox->ToFBox();
	if (NewBox.IsInside(DomainFBox))
	{
		SpawnBox->BoxTransform = Transform;
	}
	*/
	SpawnBox->BoxTransform = Transform;
}

FVector ASPHController::GetSpawnBoxTransform()
{
	return SpawnBox->BoxTransform;
}

void ASPHController::SetCollisionBoxExtents(FVector Extents)
{
	CollisionBox->BoxExtents = Extents;
}

FVector ASPHController::GetCollisionBoxExtents()
{
	return CollisionBox->BoxExtents;
}

void ASPHController::SetCollisionBoxTransform(FVector Transform)
{
	CollisionBox->BoxTransform = Transform;
}

FVector ASPHController::GetCollisionBoxTransform()
{
	return CollisionBox->BoxTransform;
}

void ASPHController::UpdateDomainBox()
{
	DomainBox->UpdateBoxLocation();
}

void ASPHController::UpdateCollisionBox()
{
	CollisionBox->UpdateBoxLocation();
}

void ASPHController::UpdateSpawnBox()
{
	SpawnBox->UpdateBoxLocation();
	NumP = (SpawnBox->BoxExtents.X / Params.H) * (SpawnBox->BoxExtents.Y / Params.H) * (SpawnBox->BoxExtents.Z / Params.H);
}

int ASPHController::GetNumP()
{
	return NumP;
}

void ASPHController::SetNiagaraArrayVector(UNiagaraComponent* NiagaraSystem, FName OverrideName,
                                           const TArray<FVector>& ArrayData)
{
	if (UNiagaraDataInterfaceArrayFloat3* ArrayDI = UNiagaraFunctionLibrary::GetDataInterface<UNiagaraDataInterfaceArrayFloat3>(NiagaraSystem, OverrideName))
	{
		FRWScopeLock WriteLock(ArrayDI->ArrayRWGuard, SLT_Write);
		ArrayDI->FloatData = ArrayData;
		ArrayDI->MarkRenderDataDirty();
	}
}

// Called when the game starts or when spawned
void ASPHController::BeginPlay()
{
	Super::BeginPlay();

	const FActorSpawnParameters SpawnParams;
	SpawnBox = GetWorld()->SpawnActor<ARenderBox>(SpawnBoxClass, FVector(0, 0, 0), FRotator(0, 0, 0), SpawnParams);

	//SpawnBox->BoxStart = FVector((Params.Domain.x / 2) - (Params.Domain.x / 4), (Params.Domain.y / 2) - (Params.Domain.y / 4), (Params.Domain.z / 2) - (Params.Domain.z / 4));
	//SpawnBox->BoxEnd = FVector((Params.Domain.x / 2) + (Params.Domain.x / 4), (Params.Domain.y / 2) + (Params.Domain.y / 4), (Params.Domain.z / 2) + (Params.Domain.z / 4));
	SpawnBox->BoxExtents = FVector(Params.Domain.x / 2.0f, Params.Domain.y / 2.0f, Params.Domain.z / 2.0f);
	SpawnBox->BoxTransform = SpawnBox->BoxExtents;
	SpawnBox->UpdateBoxLocation();
	NumP = (SpawnBox->BoxExtents.X / Params.H) * (SpawnBox->BoxExtents.Y / Params.H) * (SpawnBox->BoxExtents.Z / Params.H);

	DomainBox = GetWorld()->SpawnActor<ARenderBox>(DomainBoxClass, FVector(0, 0, 0), FRotator(0, 0, 0), SpawnParams);
	//DomainBox->BoxStart = FVector(0, 0, 0);
	//DomainBox->BoxEnd = FVector(Params.Domain.x, Params.Domain.y, Params.Domain.z);
	DomainBox->BoxExtents = FVector(Params.Domain.x, Params.Domain.y, Params.Domain.z);
	DomainBox->BoxTransform = DomainBox->BoxExtents / 2.0f;
	DomainBox->UpdateBoxLocation();

	CollisionBox = GetWorld()->SpawnActor<ARenderBox>(CollisionBoxClass, FVector(0, 0, 0), FRotator(0, 0, 0), SpawnParams);
	//CollisionBox->BoxStart = FVector(15.0f, 15.0f, 5.0f);
	//CollisionBox->BoxEnd = FVector(45.0f, 45.0f, 15.0f);
	CollisionBox->BoxExtents = FVector(30.0f, 30.0f, 15.0f);
	CollisionBox->BoxTransform = FVector(30.0f, 30.0f, 7.5f);
	CollisionBox->UpdateBoxLocation();
	
	NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);

	Params.Visc = 10.0f;
	Params.G = make_float3(0.0f, 0.0f, -9.8f);

	Params.DoCollisions = true;
}

float3 ASPHController::FVectorToFloat3(FVector V)
{
	return make_float3(V.X, V.Y, V.Z);
}

FVector ASPHController::Float3ToFVector(float3 V)
{
	return FVector(V.x, V.y, V.z);
}

// Called every frame
void ASPHController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SimShouldTick)
	{
		/*
		Params.CollisionBoxStart = make_float3(CollisionBox->BoxStart.X, CollisionBox->BoxStart.Y, CollisionBox->BoxStart.Z);
		Params.CollisionBoxEnd = make_float3(CollisionBox->BoxEnd.X, CollisionBox->BoxEnd.Y, CollisionBox->BoxEnd.Z);
		FVector R = (CollisionBox->BoxEnd - CollisionBox->BoxStart) / 2.0f;
		FVector BoxStart = -1.0f * R;
		//float3 BoxStart = Params.CollisionBoxStart - (Params.CollisionBoxStart + R);
		FVector BoxEnd = R;
		//float3 BoxEnd = Params.CollisionBoxEnd - (Params.CollisionBoxStart + R);
		FVector ParamCollisionBox = BoxStart.GetAbs() + BoxEnd;
		FVector ParamCollisionBoxTransform = CollisionBox->BoxStart + R;
		*/
		Params.CollisionBox = FVectorToFloat3(CollisionBox->BoxExtents);
		Params.CollisionBoxTransform = FVectorToFloat3(CollisionBox->BoxTransform);
		PutParticlesInCells(Params, P);
		SimStep(Params, P);

		ParticlePositions.Empty();

		for (int i = 0; i < NumP; i++)
		{
			//ParticlePositions.Add(FVector(P.X[i].x, P.X[i].y, P.X[i].z));
			ParticlePositions.Add(Float3ToFVector(P.X[i]));
		}

		NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);
		SetNiagaraArrayVector(NiagaraComponent, FName("Positions"), ParticlePositions);
	}
}

