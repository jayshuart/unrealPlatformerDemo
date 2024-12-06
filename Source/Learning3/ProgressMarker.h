// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProgressMarker.generated.h"

UCLASS()
class LEARNING3_API AProgressMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProgressMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool bMarkerReached;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* Marker;

	UPROPERTY(EditDefaultsOnly) class UBoxComponent* TriggerVolume; //square trigger space

	UFUNCTION()
		void OnTriggerEnter(UPrimitiveComponent* OverlapComp, AActor* OtherA, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
