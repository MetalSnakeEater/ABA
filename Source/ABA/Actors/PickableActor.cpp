// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

APickableActor::APickableActor() 
{
    Mesh->SetSimulatePhysics(true);

    isPicked = false;
    ThrowPower = 50000.f;
}

void APickableActor::BeginPlay() 
{
    Super::BeginPlay();
    MainChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    CharCamera = MainChar->FindComponentByClass<UCameraComponent>();
}

void APickableActor::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

    if (isPicked)
        PickUp();
}

void APickableActor::Act() 
{
    isPicked = !isPicked;
    if (isPicked)
        Mesh->SetSimulatePhysics(false);
    else
        Mesh->SetSimulatePhysics(true);
}

void APickableActor::PickUp() 
{
    FVector EndPoint = CharCamera->GetComponentLocation() + CharCamera->GetForwardVector() * 250.f;
    SetActorLocation(EndPoint);
}

void APickableActor::Throw() 
{
    isPicked = false;
    Mesh->SetSimulatePhysics(true);
    Mesh->AddForce(CharCamera->GetForwardVector() * ThrowPower * Mesh->GetMass());
}
