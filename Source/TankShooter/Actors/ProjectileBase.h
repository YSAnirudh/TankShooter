// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class TANKSHOOTER_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* ProjectileMesh = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UProjectileMovementComponent* ProjectileMovement = NULL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile", meta=(AllowPrivateAccess=true))
	float ProjectileSpeed = 1000.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage", meta=(AllowPrivateAccess=true))
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	UParticleSystem* MoveParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Particle", meta=(AllowPrivateAccess))
	TSubclassOf<UMatineeCameraShake> HitShake;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

};
