// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Birds.generated.h"

class UCapsuleComponent;

UCLASS()
class ARPGDEMO_API ABirds : public APawn
{
	GENERATED_BODY()

public:
	ABirds();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UCapsuleComponent* Capsule;
	UCapsuleComponent* Capsule1;
	
};
