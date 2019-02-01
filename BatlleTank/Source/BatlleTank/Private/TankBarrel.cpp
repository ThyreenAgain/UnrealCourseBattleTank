// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond) {


	FString TheFloatStr = FString::SanitizeFloat(DegreesPerSecond);
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate at speed: %s"), *TheFloatStr);
}

