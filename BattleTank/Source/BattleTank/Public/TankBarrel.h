// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    //-1 as max down, 1 as max up
    void Elevate (float RelativeSpeed);
    
    
private:
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreePerSecond = 10.f;
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxElevationPerSecond = 35.f;
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MinElevationPerSecond = 0.f; 
};
