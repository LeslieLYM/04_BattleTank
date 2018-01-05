// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle) {   
    //TODO: Clamp Throttle value so player can't over-ride
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation(); //Get location of the track
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //Scene Component cannot apply force
    //Apply force on the Tank
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

