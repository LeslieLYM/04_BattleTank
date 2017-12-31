// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    //-1 as max down, 1 as max up
    void Rotate (float RelativeSpeed);
    
    
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxDegreePerSecond = 28.f;
	
	
};
