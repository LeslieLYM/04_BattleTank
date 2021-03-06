// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
    Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurrentReference(UTankTurrent* TurrentToSet) {
    Turrent = TurrentToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!Barrel) {
        return;
    }
    
    if (!Turrent) {
        return;
    }
    FVector OutLaunchVelocity = FVector(0);
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, //STATIC function
                                                                        OutLaunchVelocity,
                                                                        StartLocation,
                                                                        HitLocation,
                                                                        LaunchSpeed,
                                                                        false,
                                                                        0,
                                                                        0,
                                                                        ESuggestProjVelocityTraceOption::DoNotTrace
                                                                        );
    
    //Calculate OutLaunchVelocity
    if (bHaveAimSolution) {
        //To Unit Vector
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrelTowards(AimDirection);
    } else {
        //No Aim Soulution
    }
    //Do nothing if no solution
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
    //Work out difference between Current Barrel Rotation & AimDirection
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
    
    Barrel->Elevate(DeltaRotator.Pitch); //TODO: remove magic number
    Turrent->Rotate(DeltaRotator.Yaw);
}

