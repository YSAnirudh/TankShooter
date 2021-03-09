// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret() 
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

void APawnTurret::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    RotateIfClose();
}



float APawnTurret::ReturnDistanceFromPlayer() 
{
    if (!PlayerPawn) {
        return 0.f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(),this->GetActorLocation());
}

void APawnTurret::CheckFireCondition() 
{
    if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()) return;
    if (ReturnDistanceFromPlayer() <= FireRange) {
        Fire();
    }
}


void APawnTurret::RotateIfClose() 
{
    if (!PlayerPawn || ReturnDistanceFromPlayer() >= FireRange) {
        return;
    }

    RotateTurret(PlayerPawn->GetActorLocation());
}
