// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ADCubicle.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class ADATO_API AADCubicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AADCubicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CubicleBoxComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CubicleDeskComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CubicleMonitor;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* CubicleCollisionBox;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
