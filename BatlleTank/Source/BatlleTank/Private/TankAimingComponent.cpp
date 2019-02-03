// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::setBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::setTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity(
					this,
					OutLaunchVelocity,
					StartLocation,
					HitLocation,
					LaunchSpeed,
					false,
					0,
					0,
					ESuggestProjVelocityTraceOption::DoNotTrace);

	// Calculate the out launch velocity
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	auto TankName = GetOwner()->GetName();
	auto Time = GetWorld()->GetTimeSeconds();
	FString TheFloatStr = FString::SanitizeFloat(Time);

	if (bAimSolution == true) {
		//UE_LOG(LogTemp, Warning, TEXT("%s - Tank[%s] Aiming at %s"), *TheFloatStr, *TankName, *AimDirection.ToString())
	}
	else {
		
		//UE_LOG(LogTemp, Warning, TEXT("%s - Tank[%s] Has no aiming solution"), *TheFloatStr, *TankName)
	}
	
	MoveBarrelTowards(AimDirection);

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	// Workout difference between current and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("Aimrotator: %s"), *DeltaRotator.ToString())

	// Move the barrel the right amount this frame time
	// Given a max eleveation speed and the frame time
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

}
