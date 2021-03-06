// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, to apply force to Tank
 */
UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    //Set Throttle between -1 & +1
    UFUNCTION(BlueprintCallable, Category = Input)
    void SetThrottle(float Throttle);
	
    //Max force per track in Newton
    UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 400000.f; //Assume 40000kg Tank, 1g acceleration
	
};
