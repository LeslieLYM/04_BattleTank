// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    if (!LeftTrackToSet || !RightTrackToSet) {
        return;
    }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) {
    //auto Time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw)
    
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
    
    //TODO: Prevent Double Speed by dual control
}

