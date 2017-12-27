// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurrent.h"

void UTankTurrent::Rotate (float RelativeSpeed){
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
    auto RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds; //Seconds to frame
    auto Rotation = RelativeRotation.Yaw + RotationChange;
    
    //auto  = FMath::Clamp<float>(RawNewElevation, MinElevationPerSecond, MaxElevationPerSecond);
    
//    if (RawNewRotation > 180.f) {
//        RawNewRotation -= 180.f;
//    }
//    
//    if (RawNewRotation < -180.f) {
//        RawNewRotation += 180.f;
//    }
//    UE_LOG(LogTemp, Warning, TEXT("NewRotation : %f"), Rotation)
//    SetRelativeRotation(FRotator(0, Rotation, 0));
}


