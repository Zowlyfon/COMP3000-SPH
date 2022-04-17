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

void ASPHController::SetParticleMass(float NewMass)
{
	Params.Mass = NewMass;
}

float ASPHController::GetParticleMass()
{
	return Params.Mass;
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

	NumCells = ((Params.DomainX / Params.H) + 1) * ((Params.DomainY / Params.H) + 1) * ((Params.DomainZ / Params.H) + 1);
	P = AllocateMemory(NumP, NumCells);

	Params.Visc = 10.0f;

	InitSph(Params, P);
	PutParticlesInCells(Params, P);
	FirstStep(Params, P);

	NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);
}

// Called every frame
void ASPHController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PutParticlesInCells(Params, P);
	SimStep(Params, P);

	ParticlePositions.Empty();

	for (int i = 0; i < NumP; i++)
	{
		ParticlePositions.Add(FVector(P->X[i].x, P->X[i].y, P->X[i].z));
	}

	NiagaraComponent->SetNiagaraVariableInt("NumParticles", NumP);
	SetNiagaraArrayVector(NiagaraComponent, FName("Positions"), ParticlePositions);
}

