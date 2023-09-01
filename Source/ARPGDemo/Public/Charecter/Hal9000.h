// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Hal9000.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UGroomComponent;

UCLASS()
class ARPGDEMO_API AHal9000 : public ACharacter
{
	GENERATED_BODY()

public:
	AHal9000();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category=hair)
	UGroomComponent* Hair;

	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);
};
