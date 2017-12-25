// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();
    
    auto PlayerTank = GetPlayerTank();
    
    if (!PlayerTank) {
        UE_LOG(LogTemp, Warning, TEXT("AI Controller cannot find PlayerTank"))
    } else {
        UE_LOG(LogTemp, Warning, TEXT("AI Controller (%s) found Player : %s"), *GetAITank()->GetName(), *PlayerTank->GetName())
    }
}

//Tick
void ATankAIController::Tick(float DeltaTime) {
    //Super
    Super::Tick(DeltaTime);
    
    if (GetPlayerTank()) {
        //TODO: Move towards player
        
        //Aim towards player
        GetAITank()->AimAt(GetPlayerTank()->GetActorLocation()); //GetControlledTank
        
        //Fire if ready
    }
    
}

ATank* ATankAIController::GetAITank() const { return Cast<ATank>(GetPawn()); }

ATank* ATankAIController::GetPlayerTank() const {
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn) {
        return nullptr;
    }
    return Cast<ATank>(PlayerPawn);
}

