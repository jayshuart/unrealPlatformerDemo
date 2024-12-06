// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrumblingPlatform.generated.h"

UCLASS()
class LEARNING3_API ACrumblingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrumblingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "Break") float BreakDelay;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditDefaultsOnly)
		class UBoxComponent* TriggerVolume; //square trigger space

	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnTriggerExit(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	float BreakTimer;
	bool bCrumbling;

};
