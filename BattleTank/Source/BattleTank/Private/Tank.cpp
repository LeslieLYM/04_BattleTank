// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    //No protection required due to adding component at construction
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent> (FName("Aiming Component"));

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
    TankAimingComponent->SetBarrelReference(BarrelToSet);
    Barrel = BarrelToSet;
}

void ATank::SetTurrentReference(UTankTurrent* TurrentToSet) {
    TankAimingComponent->SetTurrentReference(TurrentToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt (FVector HitLocation) {
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire () {
    if (!Barrel) {
        return;
    }
    
    //Spawn Projectile at Socket Location on Barrel
    auto Projectile = GetWorld()->SpawnActor<AProjectile>(
                                        ProjectileBlueprint,
                                        Barrel->GetSocketLocation(FName("Projectile")),
                                        Barrel->GetSocketRotation(FName("Projectile"))
                                        );
    
    Projectile->LaunchProjectile(LaunchSpeed);
}
