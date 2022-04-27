// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "sph.cuh"
#include "cuda_runtime.h"

#include "CoreMinimal.h"

#include "RenderBox.h"
#include "GameFramework/Actor.h"
#include "SPHController.generated.h"

UCLASS()
class SIMULATION_API ASPHController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPHController();

	int NumP = 12000;
	int NumCells;
	Parameters Params;
	Particles P;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	int SimStepPerFrame = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool SimShouldTick = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool SimStarted = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UNiagaraComponent* NiagaraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARenderBox> SpawnBoxClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARenderBox> DomainBoxClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARenderBox> CollisionBoxClass;

	UFUNCTION(BlueprintCallable)
	void StartSimulation();

	UFUNCTION(BlueprintCallable)
	void StopSimulation();

	UFUNCTION(BlueprintCallable)
	void PauseSimulation();

	UFUNCTION(BlueprintCallable)
	void UnpauseSimulation();

	// Getters and Setters
	UFUNCTION(BlueprintCallable)
	int GetNumP();
	
	UFUNCTION(BlueprintCallable)
	void SetParticleMass(float NewMass);

	UFUNCTION(BlueprintCallable)
	float GetParticleMass();

	UFUNCTION(BlueprintCallable)
	void SetViscosity(float NewViscosity);

	UFUNCTION(BlueprintCallable)
	float GetViscosity();

	UFUNCTION(BlueprintCallable)
	void SetRestDensity(float NewRestDensity);

	UFUNCTION(BlueprintCallable)
	float GetRestDensity();

	UFUNCTION(BlueprintCallable)
	void SetGasConstant(float NewGasConstant);

	UFUNCTION(BlueprintCallable)
	float GetGasConstant();

	UFUNCTION(BlueprintCallable)
	void SetGravityScale(float NewGravityScale);

	UFUNCTION(BlueprintCallable)
	float GetGravityScale();

	UFUNCTION(BlueprintCallable)
	void SetH(float newH);

	UFUNCTION(BlueprintCallable)
	float GetH();

	UFUNCTION(BlueprintCallable)
	void SetDomainBoxExtents(FVector Extents);

	UFUNCTION(BlueprintCallable)
	FVector GetDomainBoxExtents();

	UFUNCTION(BlueprintCallable)
	void SetSpawnBoxExtents(FVector Extents);

	UFUNCTION(BlueprintCallable)
	FVector GetSpawnBoxExtents();

	UFUNCTION(BlueprintCallable)
	void SetSpawnBoxTransform(FVector Transform);

	UFUNCTION(BlueprintCallable)
	FVector GetSpawnBoxTransform();

	UFUNCTION(BlueprintCallable)
	void SetCollisionBoxExtents(FVector Extents);

	UFUNCTION(BlueprintCallable)
	FVector GetCollisionBoxExtents();

	UFUNCTION(BlueprintCallable)
	void SetCollisionBoxTransform(FVector Transform);

	UFUNCTION(BlueprintCallable)
	FVector GetCollisionBoxTransform();

	UFUNCTION(BlueprintCallable)
	void UpdateDomainBox();

	UFUNCTION(BlueprintCallable)
	void UpdateSpawnBox();

	UFUNCTION(BlueprintCallable)
	void UpdateCollisionBox();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// https://github.com/monguri/UE4NiagaraSandbox
	void SetNiagaraArrayVector(UNiagaraComponent* NiagaraSystem, FName OverrideName, const TArray<FVector>& ArrayData);

	TArray<FVector> ParticlePositions;

	ARenderBox* SpawnBox;

	ARenderBox* DomainBox;

	ARenderBox* CollisionBox;

	float3 FVectorToFloat3(FVector V);
	FVector Float3ToFVector(float3 V);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
