// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

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
        GetControlledTank()->AimAt(HitLocation);
    }
}

//Get world loaction through crosshair (Line Trace), true if hit landscape
bool ATankPlayerController::GetSideRayHitLocation(FVector& OutHitLocation) const {
    //Find Crosshair Position in pixel coordinate
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
    
    //De-project Screen Position of Crosshair to world position (look direction)
    //Can use GetHitResultAtScreenPosition() instead
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection)) { //Look Direction is unit vector
        //Line Trace along look direction, See what is hit (up to Max Range)
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
        return true;
    }
    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
    FVector CameraWorldLocation;
    
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const {
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation(); //since convert from the screenlocation, not pawn location
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    //If Line Trace succeed
    if (GetWorld()->LineTraceSingleByChannel(
                                             HitResult,
                                             StartLocation,
                                             EndLocation,
                                             ECollisionChannel::ECC_Visibility
                                             )) {
        OutHitLocation = HitResult.Location;
        return true;
    }
        //Set Hit Location, return true
    //Else, return false
    OutHitLocation = FVector(0);
    return false;
}




