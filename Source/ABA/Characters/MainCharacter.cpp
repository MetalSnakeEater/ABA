// Fill out your copyright notice in the Description page of Project Settings.


#include "ABA/Characters/MainCharacter.h"
#include "ABA/Actors/InteractableActor.h"
#include "ABA/Actors/PickableActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AMainCharacter::Jump);
	PlayerInputComponent->BindAction("Interact",IE_Pressed, this, &AMainCharacter::Interact);
	PlayerInputComponent->BindAction("Throw",IE_Pressed, this, &AMainCharacter::ThrowObject);
}

void AMainCharacter::MoveForward(float Val) 
{
	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector, Val);
}

void AMainCharacter::MoveRight(float Val) 
{
	FVector RightVector = GetActorRightVector();
	AddMovementInput(RightVector, Val);
}

void AMainCharacter::Interact() 
{
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * 300;
	FHitResult HitResult;
	
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);

	if (AInteractableActor* InteractActor = Cast<AInteractableActor>(HitResult.GetActor()))
	{
		InteractActor->Act();
	}
}

void AMainCharacter::ThrowObject() 
{
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * 300;
	FHitResult HitResult;
	
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);

	if (APickableActor* ThrowActor = Cast<APickableActor>(HitResult.GetActor()))
	{
		ThrowActor->Throw();
	}
}
