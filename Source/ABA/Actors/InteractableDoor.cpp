// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDoor.h"


AInteractableDoor::AInteractableDoor() 
{
    isClosed = true; 
    isOpening = false;
    isClosing = false;
}

void AInteractableDoor::BeginPlay() 
{
    Super::BeginPlay();
    CloseRot = GetActorRotation();
    OpenRot = CloseRot + FRotator(0, 90.f, 0);
}

void AInteractableDoor::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

    if (isOpening)
        Open();
    if (isClosing)
        Close();
}

void AInteractableDoor::Act() 
{
    if (isClosed)
    {
        isClosed = false;
        isOpening = true;
        isClosing = false;
    }
    else
    {
        isClosed = true;
        isOpening = false;
        isClosing = true;
    }
}

void AInteractableDoor::Open() 
{
    FRotator CurrentRot = GetActorRotation();
    if (FMath::IsNearlyEqual(CurrentRot.Yaw, OpenRot.Yaw, 1.f))
    {
        isOpening = false;
    }
    else
    {
        CurrentRot = FMath::Lerp(CurrentRot, OpenRot, 0.1f);
        SetActorRotation(CurrentRot);
    }
}

void AInteractableDoor::Close() 
{
    FRotator CurrentRot = GetActorRotation();
    if (FMath::IsNearlyEqual(CurrentRot.Yaw, CloseRot.Yaw, 1.f))
    {
        isClosing = false;
    }
    else
    {
        CurrentRot = FMath::Lerp(CurrentRot, CloseRot, 0.1f);
        SetActorRotation(CurrentRot);
    }
}
