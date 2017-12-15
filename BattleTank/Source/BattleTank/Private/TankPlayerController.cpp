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
        //UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *HitLocation.ToString())
        
        
        //TODO: Tell controlled tank aim at the point
    }
}

//Get world loaction through crosshair (Line Trace), true if hit landscape
bool ATankPlayerController::GetSideRayHitLocation(FVector& OutHitLocation) const {
    //Find Crosshair Position in pixel coordinate
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    
    //De-project Screen Position of Crosshair to world position (look direction)
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection)) {
        UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *LookDirection.ToString()) //Unit Vector
    }
    
    //Line Trace along look direction, See what is hit (up to Max Range)
    OutHitLocation = FVector(1.f);
    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
    FVector CameraWorldLocation;
    
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}


