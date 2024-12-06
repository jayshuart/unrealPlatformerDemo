// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AJumpPad.generated.h"

UCLASS()
class LEARNING3_API AAJumpPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAJumpPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* JumpPadMesh; //our visible asset

	UPROPERTY(EditDefaultsOnly)
		class UBoxComponent* JumpPadTriggerVolume; //square trigger space

	//mats for on and off
	UPROPERTY(EditDefaultsOnly)
		class UMaterialInterface* InactiveMat;

	UPROPERTY(EditDefaultsOnly)
		class UMaterialInterface* ActiveMat;

	UFUNCTION()
		void JumpPadTriggered(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void JumpPadExitTrigger(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
