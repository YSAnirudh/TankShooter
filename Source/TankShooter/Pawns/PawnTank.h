// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TANKSHOOTER_API APawnTank : public APawnBase
{
	GENERATED_BODY()

private:
	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speed", meta=(AllowPrivateAccess=true))
	float MoveSpeed = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Speed", meta=(AllowPrivateAccess=true))	
	float RotateSpeed = 200.f;

	FVector MoveDirection;
	FQuat RotateDirection;

	APlayerController* PlayerPawn = NULL;
	bool bIsPlayerAlive = true;

	//Functions
	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	USpringArmComponent* SpringArm = NULL;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = true))
	UCameraComponent* Camera = NULL;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	APawnTank();
	virtual void HandleDestruction() override;
	bool GetIsPlayerAlive();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
