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
	
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString())
		// If it hits the landscape
			// tell controlled tank to aim at this point
	
	}
	
}

// Get World Location of linetrace through the crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}



