// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class AProjectileBase;
UCLASS()
class TANKSHOOTER_API APawnBase : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	APawnBase();
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UCapsuleComponent* CapsuleComponent = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* TurretMesh = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	USceneComponent* ProjectileSpawnPoint = NULL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile", meta=(AllowPrivateAccess=true))
	TSubclassOf<AProjectileBase> Projectile = NULL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	USoundBase* DeathSound;

protected:

	virtual void RotateTurret(FVector TargetLookDirection);
	virtual void HandleDestruction();
	virtual void Fire();
};
