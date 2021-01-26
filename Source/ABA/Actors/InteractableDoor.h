// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableDoor.generated.h"

/**
 * 
 */
UCLASS()
class ABA_API AInteractableDoor : public AInteractableActor
{
	GENERATED_BODY()

private:
	// Variables
	FRotator OpenRot;
	FRotator CloseRot;
	bool isClosed;
	bool isOpening;
	bool isClosing;

	// Functions
	void Open();
	void Close();
public:
	AInteractableDoor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Act() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
