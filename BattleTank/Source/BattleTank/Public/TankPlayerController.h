// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = 0.5f; //50% left of screen
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 0.3f; //30% down of screen
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000;
    
    ATank* GetControlledTank() const;
    //Start tank moving barrel so shot hit at intersection of crosshair & world
    void AimTowardsCrosshair();
    //Return an OUT parameter Hit Location, true if hit landscape
    bool GetSideRayHitLocation(FVector& OutHitLocation) const;
    
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
    
    
};
