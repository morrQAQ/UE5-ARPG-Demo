// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "ARPGDemo/DebugMacro.h"
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play !"))

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, FString("print on screen message !"));
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld *World = GetWorld();
	if (World)
	{
		FVector Location = GetActorLocation();
		DRAW_SPHERE(Location);
		FVector Forward = GetActorForwardVector();
		DrawDebugLine(World, Location, (Forward + Location) * 100, FColor::Black, true, -1, 0, 5.f);
	}
}
