// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotationPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ROTATE POINT"));
	RootComponent = RotationPoint;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	BoxCollider->SetupAttachment(RotationPoint);
	

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	PlatformMesh->SetupAttachment(BoxCollider);

	RotationRate = FRotator(0.0f, 10.0f, 0.0f);
}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationRate * DeltaTime);
}

