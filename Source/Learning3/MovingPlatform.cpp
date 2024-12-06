// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Components/BoxComponent.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = BoxCollider; //make collider the root

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	PlatformMesh->SetupAttachment(BoxCollider); //ensure mesh is aligned with the collider

	MovementComp = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("Movement Component"));

	//default behavior
	MovementComp->Duration = 5.0f;
	MovementComp->bAutoActivate = true;
	MovementComp->bSweep = true;
	MovementComp->BehaviourType = EInterpToBehaviourType::PingPong;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//gather path nodes form viewport
	MovementComp->ControlPoints.Add(FInterpControlPoint(FVector(0.0f, 0.0f, 0.0f), true)); //first point is our current local point so we dont snap to some weird start point

	for (int i = 0; i < MovePath.Num(); i++) {
		MovementComp->ControlPoints.Add(FInterpControlPoint(MovePath[i], true));
	}

	MovementComp->FinaliseControlPoints(); //lock in the path
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

