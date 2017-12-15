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
    
    FVector HitLocation; //OUT parameter
    if (GetSideRayHitLocation(HitLocation)) { //Side effect, Line Trace
        UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *HitLocation.ToString())
        
        
        //TODO: Tell controlled tank aim at the point
    }
}

//Get world loaction through crosshair (Line Trace), true if hit landscape
bool ATankPlayerController::GetSideRayHitLocation(FVector& OutHitLocation) const {
    //Line Trace
    //If hit something
        //Hit is made & return true
        //Hit Location will be updated
    OutHitLocation = FVector(1.f);
    return true;
}
