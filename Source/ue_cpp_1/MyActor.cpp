// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "string"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector OriginLocation = FVector(0, 0, 50);
	SetActorLocation(OriginLocation);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	index++;

	if (index < 10)

	{
		Move();
		Turn();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(6, 5, FColor::Red, FString::Printf(TEXT("Index : %d"), index));
		}
		UE_LOG(LogTemp, Warning, TEXT("Index : %d"), index);
	}
	
}

void AMyActor::Move()
{
	if (!TriggerEvent()) return;
	changed_Loc++;

	FVector Target;
	Target.X = FMath::FRandRange(-50.0, 50.0);
	Target.Y = FMath::FRandRange(-50.0, 50.0);
	Target.Z = 0;

	double Length = Distance(GetActorLocation(), Target);
	Moved_Length += Length;

	AddActorWorldOffset(Target);

	
	FVector CurrentLocation = GetActorLocation();
	

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(5, 5, FColor::Red, *CurrentLocation.ToString());
		GEngine->AddOnScreenDebugMessage(4, 5, FColor::Red, FString::Printf(TEXT("C_Loc : %d"), changed_Loc));
		GEngine->AddOnScreenDebugMessage(3, 5, FColor::Red, FString::Printf(TEXT("Moved_Length : %f"), Moved_Length));
	}
	UE_LOG(LogTemp, Warning, TEXT("CurrentLocation : %s"), *CurrentLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("changed_Loc : %d"), changed_Loc);
	UE_LOG(LogTemp, Warning, TEXT("Moved_Length : %f"), Moved_Length);
}

void AMyActor::Turn()
{
	if (!TriggerEvent()) return;
	changed_Rot++;

	FRotator DeltaRotation;

	DeltaRotation.Yaw = FMath::FRandRange(-180.0, 180.0);
	DeltaRotation.Pitch = 0;
	DeltaRotation.Roll = 0;

	AddActorWorldRotation(DeltaRotation);

	FRotator CurrentRotation = GetActorRotation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 5, FColor::Red, *DeltaRotation.ToString());
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, FString::Printf(TEXT("C_Rot : %d"), changed_Rot));
	}
	UE_LOG(LogTemp, Warning, TEXT("DeltaRotation : %s"), *DeltaRotation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("changed_Rot : %d"), changed_Rot);
}

bool AMyActor::TriggerEvent()
{

	if (FMath::RandRange(-99.0, 100.0) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double AMyActor::Distance(FVector A, FVector B)
{

	return FVector::Dist(A, B);
}
