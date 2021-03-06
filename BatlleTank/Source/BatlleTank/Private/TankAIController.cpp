// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto controlledTank = GetControlledTank();
	/*
	if (controlledTank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Found: %s"), *(controlledTank->GetName()))
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AI Tank NOT Found:"))
	}

	auto playerTank = GetPlayerTank();

	if (!playerTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController did not find a player tank:"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController Found player Tank: %s"), *(playerTank->GetName()))
	}
	*/

}

void ATankAIController::Tick(float DeltaSeconds)
{
	auto PlayerTank = GetPlayerTank();
	auto ControlledTank = GetControlledTank();

	if (GetPlayerTank()) {
		// tell controlled tank to aim at this point
		GetControlledTank()->AimAt(PlayerTank->GetTargetLocation());
		//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
		//GetControlledTank()->Fire();
	}
}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

