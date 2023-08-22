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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sin Param")
	float Amplitude = 2.5f;

	UFUNCTION(BlueprintPure)
	float TransformedSin() const;

	UFUNCTION(BlueprintPure)
	float TransformedCos() const;

private:
	UPROPERTY(VisibleAnywhere, Category="Sin Param")
	float RunningTime;

	UPROPERTY(EditInstanceOnly, Category="Sin Param")
	float TimeConstant = 5.f;

	UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess="true"))
	float EditAnywhere;
};
