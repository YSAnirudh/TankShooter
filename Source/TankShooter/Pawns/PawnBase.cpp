// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "TankShooter/Actors/ProjectileBase.h"
#include "Engine/World.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector TargetLookDirection) 
{
	FVector TargetDirectionCleaned = FVector(TargetLookDirection.X, TargetLookDirection.Y, TurretMesh->GetComponentLocation().Z);
	FVector LookDirection = TargetDirectionCleaned - TurretMesh->GetComponentLocation();


	TurretMesh->SetWorldRotation(LookDirection.Rotation());
}

void APawnBase::HandleDestruction() 
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathParticle, GetActorLocation(), GetActorRotation());
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), DeathSound, GetActorLocation(), GetActorRotation());
}

void APawnBase::Fire() 
{
	if(Projectile) {
		AProjectileBase* TempProjectile;
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
		TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(Projectile, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}

