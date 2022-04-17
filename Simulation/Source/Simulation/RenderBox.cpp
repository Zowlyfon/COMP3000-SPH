// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderBox.h"

// Sets default values
ARenderBox::ARenderBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));

	RootComponent = BoxMesh;
}

void ARenderBox::UpdateBoxLocation()
{
	/*
	const FVector BoxSize = BoxEnd - BoxStart;
	const FVector BoxWorldLocation = FVector(BoxStart.X + (BoxSize.X / 2.0f), BoxStart.Y + (BoxSize.Y / 2.0f), BoxStart.Z);
	BoxMesh->SetWorldLocation(BoxWorldLocation);
	BoxMesh->SetWorldScale3D(FVector((BoxEnd.X - BoxStart.X) / 100.0f, (BoxEnd.Y - BoxStart.Y) / 100.0f, (BoxEnd.Z - BoxStart.Z) / 100.0f));
	*/
	BoxMesh->SetWorldLocation(FVector(BoxTransform.X, BoxTransform.Y, BoxTransform.Z - BoxExtents.Z / 2.0f));
	BoxMesh->SetWorldScale3D(BoxExtents / 100.0f);
}

FBox ARenderBox::ToFBox()
{
	return FBox(BoxTransform - BoxExtents / 2.0f, BoxTransform + BoxExtents / 2.0f);
}

// Called when the game starts or when spawned
void ARenderBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARenderBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

