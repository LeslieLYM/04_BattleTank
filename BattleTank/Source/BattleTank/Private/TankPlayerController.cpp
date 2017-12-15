// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    
    if (!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller is missing pawn"))
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Player Controller Possessed : %s"), *ControlledTank->GetName())
    }
}

//Tick
void ATankPlayerController::Tick(float DeltaTime) {
    //Super
    Super::Tick(DeltaTime);
    
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

void ATankPlayerController::AimTowardsCrosshair() {
    if (!GetControlledTank()) { return; }
    //Get world loaction through crosshair (Line Trace)
    //If hits landscape
        //Tell controlled tank aim at the point
}
