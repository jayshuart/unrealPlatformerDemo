// Fill out your copyright notice in the Description page of Project Settings.


#include "CrumblingPlatform.h"
#include "Learning3Character.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACrumblingPlatform::ACrumblingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = BoxCollider; //make collider the root

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	PlatformMesh->SetupAttachment(BoxCollider); //ensure mesh is aligned with the collider

	//init trigger volume
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	TriggerVolume->SetupAttachment(PlatformMesh); //keeps trigger near jump pad visible mesh

	BreakDelay = 3.0f;
	BreakTimer = BreakDelay;
	bCrumbling = false;

}

// Called when the game starts or when spawned
void ACrumblingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//subscribe event listeners
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ACrumblingPlatform::OnTriggerEnter);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ACrumblingPlatform::OnTriggerExit);
	
}

// Called every frame
void ACrumblingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bCrumbling && BreakTimer > 0){
		BreakTimer -= DeltaTime;

		if (BreakTimer < 0) {
			PlatformMesh->SetSimulatePhysics(true);
		}
	}

}

void ACrumblingPlatform::OnTriggerEnter(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//confirm we have the character
	if (ALearning3Character* player = Cast<ALearning3Character>(OtherA)) {
		//ensure we have the capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == player->GetCapsuleComponent()) {
			bCrumbling = true;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
		}
	}
}

void ACrumblingPlatform::OnTriggerExit(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//confirm we have the character
	if (ALearning3Character* player = Cast<ALearning3Character>(OtherA)) {
		//ensure we have the capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == player->GetCapsuleComponent()) {
			//bCrumbling = false;
			//BreakTimer = BreakDelay;
		}
	}
}

