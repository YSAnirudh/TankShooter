// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;
/**
 * 
 */
UCLASS()
class TANKSHOOTER_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:
	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speed", meta=(AllowPrivateAccess=true))
	float FireRange = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speed", meta=(AllowPrivateAccess=true))
	float FireRate = 2.f;

	void RotateIfClose();
	float ReturnDistanceFromPlayer();
	void CheckFireCondition();

	APawnTank* PlayerPawn = NULL;
protected:
	APawnTurret();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void HandleDestruction() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
