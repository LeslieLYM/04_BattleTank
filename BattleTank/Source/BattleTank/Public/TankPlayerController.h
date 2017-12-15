// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
    //Getter
    ATank* GetControlledTank() const;
    //Start tank moving barrel so shot hit at intersection of crosshair & world
    void AimTowardsCrosshair();
    //Return an OUT parameter Hit Location, true if hit landscape
    bool GetSideRayHitLocation(FVector& OutHitLocation) const;
};
