// Fill out your copyright notice in the Description page of Project Settings.

#include "ADCubicle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AADCubicle::AADCubicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubicleBoxComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubicleBoxComp"));
	RootComponent = CubicleBoxComp;

	CubicleDeskComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubicleDeskComp"));
	CubicleDeskComp->SetupAttachment(RootComponent);

	CubicleMonitor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubicleMonitor"));
	CubicleMonitor->SetupAttachment(CubicleDeskComp);

	CubicleCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CubicleCollisionBox"));
	CubicleCollisionBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AADCubicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AADCubicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

