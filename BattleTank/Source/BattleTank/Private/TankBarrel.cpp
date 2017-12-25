// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate (float DegreesPerSecond){
    //Move barrel right amount of rotation this frame
    //Give Max elevation speed & frame time
    UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() called at speed %f"), DegreesPerSecond)
}


