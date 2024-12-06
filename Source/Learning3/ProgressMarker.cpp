// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressMarker.h"
#include "Learning3Character.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AProgressMarker::AProgressMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Marker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MarkerMesh"));
	//RootComponent = Marker;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	TriggerVolume->SetupAttachment(Marker); //keeps trigger near jump pad visible mesh

	bMarkerReached = false;

}

// Called when the game starts or when spawned
void AProgressMarker::BeginPlay()
{
	Super::BeginPlay();

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AProgressMarker::OnTriggerEnter);
}

// Called every frame
void AProgressMarker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProgressMarker::OnTriggerEnter(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bMarkerReached) { return;  }

	//confirm we have the character
	if (ALearning3Character* player = Cast<ALearning3Character>(OtherA)) {
		//ensure we have the capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == player->GetCapsuleComponent()) {
			bMarkerReached = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Marker Reached"));

			player->LastMarker = this;
		}
	}
}

