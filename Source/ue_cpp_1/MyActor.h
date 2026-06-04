// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UE_CPP_1_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	int index = 0;
	int changed_Loc = 0;
	int changed_Rot = 0;
	
	double Moved_Length = 0.0;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move();
	void Turn();
	bool TriggerEvent();
	double Distance(FVector A, FVector B);
};
