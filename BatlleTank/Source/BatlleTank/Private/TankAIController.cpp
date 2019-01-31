// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto controlledTank = getControlledTank();

	if (controlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Found: %s"), *controlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AI Tank NOT Found:"))
	}



}

ATank* ATankAIController::getControlledTank() const {

	return Cast<ATank>(GetPawn());
}

