// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HalAnimInstance.generated.h"
class AHal9000;
class UCharacterMovementComponent;
UCLASS()
class ARPGDEMO_API UHalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	AHal9000* hal9000;

	UPROPERTY(BlueprintReadOnly,Category =Movement)
	UCharacterMovementComponent* Movement;

	UPROPERTY(BlueprintReadOnly,Category=Movement)
	float GroundSpeed;
	
private:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
