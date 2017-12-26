// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate (float RelativeSpeed){
    //Move barrel right amount of rotation this frame
    //Give Max elevation speed & frame time
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
    auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds; //Seconds to frame
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    
    auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationPerSecond, MaxElevationPerSecond);
    
    SetRelativeRotation(FRotator(Elevation, 0, 0));
    
    
}


