// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class ABA_API AInteractableActor : public AActor
{
	GENERATED_BODY()

private:
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when interacted by player
	virtual void Act();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

};
