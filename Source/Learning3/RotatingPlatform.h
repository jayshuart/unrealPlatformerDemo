// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class LEARNING3_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true")) USceneComponent* RotationPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation", meta = (ExposeOnSpawn = "true", MakeEditWidget = "true")) FRotator RotationRate;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Components") class UBoxComponent* BoxCollider;
	UPROPERTY(EditDefaultsOnly, Category = "Components") class UStaticMeshComponent* PlatformMesh;

	float AngleAxis;
};
