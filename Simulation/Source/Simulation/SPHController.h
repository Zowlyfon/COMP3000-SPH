// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SPH_CUDA.cuh"
#include "cuda_runtime.h"

#include "CoreMinimal.h"
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
	Particles *P;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UNiagaraComponent* NiagaraComponent;

	UFUNCTION(BlueprintCallable)
	void SetParticleMass(float NewMass);

	UFUNCTION(BlueprintCallable)
	float GetParticleMass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// https://github.com/monguri/UE4NiagaraSandbox
	void SetNiagaraArrayVector(UNiagaraComponent* NiagaraSystem, FName OverrideName, const TArray<FVector>& ArrayData);

	TArray<FVector> ParticlePositions;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
