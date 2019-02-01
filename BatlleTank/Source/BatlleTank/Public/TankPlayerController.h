// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATLLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	ATankPlayerController();

	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(EditAnyWhere)
	float CrossHairX_ViewportDistribution = 0.5f;

	UPROPERTY(EditAnyWhere)
	float CrossHairY_ViewportDistribution = 0.333f;

	// in KM
	UPROPERTY(EditAnyWhere)
	float LineTraceRange = 1000000.0;
	
	ATank* GetControlledTank() const;

	// Move the barrel towards the crosshair
	void AimTowardsCrosshair();

	// return an OUT parameter and return true if hit is not sky.
	bool GetSightRayHitLocation(FVector& Hitlocation) const;

	// Deproject the screen position to the world direction
	bool GetLookDirection(FVector2D CrossHairScreenPos, FVector& LookDirection) const;

	// What in the wordl is our crosshair hitting
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
};
