// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class ARPGDEMO_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	float Amplitude = 2.5f;
	UPROPERTY(EditAnywhere)
	float RunningTime;
	UPROPERTY(EditInstanceOnly)
	float TimeConstant = 5.f;
};
