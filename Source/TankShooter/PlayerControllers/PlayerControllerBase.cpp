// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"


APlayerControllerBase::APlayerControllerBase() 
{
    
}

void APlayerControllerBase::SetPlayerEnabledState(bool bPlayerControl) 
{
    if (bPlayerControl) {
        GetPawn()->EnableInput(this);
    } else {
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = bPlayerControl;
}
