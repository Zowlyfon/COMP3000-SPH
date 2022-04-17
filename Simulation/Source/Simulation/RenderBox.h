// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RenderBox.generated.h"

UCLASS()
class SIMULATION_API ARenderBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARenderBox();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector BoxStart;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector BoxEnd;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector BoxExtents;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector BoxTransform;

	UFUNCTION(BlueprintCallable)
	void UpdateBoxLocation();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* BoxMesh;

	UFUNCTION(BlueprintCallable)
	FBox ToFBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
