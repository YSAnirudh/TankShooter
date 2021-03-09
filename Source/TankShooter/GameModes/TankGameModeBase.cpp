// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "TankShooter/Pawns/PawnTank.h"
#include "Kismet/GameplayStatics.h"
#include "TankShooter/Pawns/PawnTurret.h"
#include "TankShooter/PlayerControllers/PlayerControllerBase.h"
#define OUT
void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
	
}
void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
	if (DeadActor == PlayerPawn) {
		//set game over false
		PlayerPawn->HandleDestruction();
		HandleGameOver(false);

		if (PlayerController) {
			PlayerController->SetPlayerEnabledState(false);
		}
	} else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor)) {
		DestroyedTurret->HandleDestruction();
		NoOfTurrets--;
		if (NoOfTurrets == 0) {
			HandleGameOver(true);
		}
	}
}

void ATankGameModeBase::HandleGameStart() 
{
    NoOfTurrets = GetNoOfTurrets();
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerController = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	GameStart();

	if (PlayerController) {
		PlayerController->SetPlayerEnabledState(false);

		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(PlayerController, &APlayerControllerBase::SetPlayerEnabledState, true);

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, StartDelay, false);
	}
}

void ATankGameModeBase::HandleGameOver(bool bPlayerWon) 
{
    GameOver(bPlayerWon);
}

int32 ATankGameModeBase::GetNoOfTurrets() 
{
	TArray<AActor*> Turrets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), OUT Turrets);
	return Turrets.Num();
}
