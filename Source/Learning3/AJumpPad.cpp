// Fill out your copyright notice in the Description page of Project Settings.


#include "AJumpPad.h"
#include "Learning3Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AAJumpPad::AAJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//link our mesh
	JumpPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Jump Pad Mesh"));

	//init trigger volume
	JumpPadTriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	JumpPadTriggerVolume->SetupAttachment(JumpPadMesh); //keeps trigger near jump pad visible mesh

}

// Called when the game starts or when spawned
void AAJumpPad::BeginPlay()
{
	Super::BeginPlay();

	//set inital mat state
	JumpPadMesh->SetMaterial(0, InactiveMat);

	//subscribe event listeners
	JumpPadTriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AAJumpPad::JumpPadTriggered);
	JumpPadTriggerVolume->OnComponentEndOverlap.AddDynamic(this, &AAJumpPad::JumpPadExitTrigger);
	
}

// Called every frame
void AAJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAJumpPad::JumpPadTriggered(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//confirm we have the character
	if (ALearning3Character* player = Cast<ALearning3Character>(OtherA)) {
		//ensure we have the capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == player->GetCapsuleComponent()) {
			//change mat
			JumpPadMesh->SetMaterial(0, ActiveMat);

			//increase players jump velocity
			player->GetCharacterMovement()->JumpZVelocity *= 2.5;
		}
	}
}

void AAJumpPad::JumpPadExitTrigger(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//confirm we have the character
	if (ALearning3Character* player = Cast<ALearning3Character>(OtherA)) {
		//ensure we have the capsule component
		if (Cast<UCapsuleComponent>(OtherComp) == player->GetCapsuleComponent()) {
			//change mat
			JumpPadMesh->SetMaterial(0, InactiveMat);

			//reset players jump velocity
			player->GetCharacterMovement()->JumpZVelocity /= 2.5;
		}
	}
}

