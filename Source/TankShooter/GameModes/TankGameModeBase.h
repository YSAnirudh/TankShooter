// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTank;
class APawnTurret;
class APlayerControllerBase;
UCLASS()
class TANKSHOOTER_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	int32 NoOfTurrets;
	APawnTank* PlayerPawn = NULL;
	APlayerControllerBase* PlayerController = NULL;

	int32 GetNoOfTurrets();


public:
	void ActorDied(AActor* DeadActor);

	void HandleGameStart();
	void HandleGameOver(bool bPlayerWon);
public:
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bPlayerWon);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess=true))
	int32 StartDelay = 3.f;

protected:
	virtual void BeginPlay() override;

};
