// Fill out your copyright notice in the Description page of Project Settings.

#include "ADCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AADCharacter::AADCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SprintArmComp->bUsePawnControlRotation = true;
	SprintArmComp->SetupAttachment(RootComponent);


	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SprintArmComp);
}


// Called when the game starts or when spawned
void AADCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AADCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}


void AADCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}


void AADCharacter::PlayerCrouch()
{
	Crouch();
}

// Called every frame
void AADCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called to bind functionality to input
void AADCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AADCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AADCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AADCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AADCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AADCharacter::Jump);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AADCharacter::PlayerCrouch);
}

