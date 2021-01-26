// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PickableActor.generated.h"

class ACharacter;
class UCameraComponent;

UCLASS()
class ABA_API APickableActor : public AInteractableActor
{
	GENERATED_BODY()
private:
	// Variables
	bool isPicked;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float ThrowPower;
	ACharacter* MainChar;
	UCameraComponent* CharCamera;

	// Functions
	void PickUp();

public:
	APickableActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Act() override;
	void Throw();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
