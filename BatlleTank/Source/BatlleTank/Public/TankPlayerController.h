// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
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
	
	ATank* GetControlledTank() const;

	// Move the barrel towards the crosshair
	void AimTowardsCrosshair();

	// return an OUT parameter and return true if hit is not sky.
	bool GetSightRayHitLocation(FVector& Hitlocation) const;


	
};
