// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	
	Super::BeginPlay();

	auto controlledTank = getControlledTank();

	if (controlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Found: %s"), *controlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Tank NOT Found:"))
	}


}

ATank* ATankPlayerController::getControlledTank() const {

	return Cast<ATank>(GetPawn());
}



