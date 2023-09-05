// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

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

	template <typename T>
	static T Avg(T First, T Second);

private:
	UPROPERTY(VisibleAnywhere, Category="Sin Param")
	float RunningTime;

	UPROPERTY(EditInstanceOnly, Category="Sin Param")
	float TimeConstant = 5.f;

	UPROPERTY()
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
	                     bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);
};

template <typename T>
T AItem::Avg(T First, T Second) { return (First + Second) / 2; }
