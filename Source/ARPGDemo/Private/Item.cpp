#include "Item.h"
#include "ARPGDemo/DebugMacro.h"

AItem::AItem(): AActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play !"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green,
		                                 FString("print on screen message !"));
	}
}

float AItem::TransformedSin() const
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos() const
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	const FVector Location = GetActorLocation();
	const FVector Forward = GetActorForwardVector();
	DRAW_SPHERE_EVERY_FRAME(Location);
	DRAW_LINE_EVERY_FRAME(Location, Location-Forward);
}
