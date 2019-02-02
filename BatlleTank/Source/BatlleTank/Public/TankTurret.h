// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATLLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// -1 max down speed, +1 is max up speed
	void Rotate(float ReleativeSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25;
	
};
