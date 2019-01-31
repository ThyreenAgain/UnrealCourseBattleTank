// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

// Sets default values
ATankPlayerController::ATankPlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ATankPlayerController::BeginPlay() {
	
	Super::BeginPlay();

	auto controlledTank = GetControlledTank();

	if (controlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Found: %s"), *(controlledTank->GetName()))
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Tank NOT Found:"))
	}


}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is ticking"))

	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation)) {
	
		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString())
		// If it hits the landscape
			// tell controlled tank to aim at this point
	
	}
	
}

// Get World Location of linetrace through the crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position relative to the screensize
	int32 ViewPortSizeX, ViewPortSizeY;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	
	auto CrossHairScreenPos = FVector2D(ViewPortSizeX * CrossHairX_ViewportDistribution,
										ViewPortSizeY * CrossHairY_ViewportDistribution);
	
	FVector LookDirection;
	if (GetLookDirection(CrossHairScreenPos, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Crosshair worldlocation: %s"), *LookDirection.ToString())
	}

	// Linetrace through that world direction and see what we hit (take into account the range)
	return true;
}

// Deproject the screen position to the world direction
bool ATankPlayerController::GetLookDirection(FVector2D CrossHairScreenPos, FVector& LookDirection) const {
	
	FVector WorldLocation; //OUT params
	return DeprojectScreenPositionToWorld(CrossHairScreenPos.X, CrossHairScreenPos.Y,
											WorldLocation, LookDirection);
	
}



