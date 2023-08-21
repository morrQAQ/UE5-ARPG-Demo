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

	SetActorLocation(FVector(0.f, 0.f, 50.f));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green,
		                                 FString("print on screen message !"));
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	constexpr float Speed = 5.f;
	AddActorLocalOffset(
		FVector(0.f, 0.f, Speed * DeltaTime));

	const FVector Location = GetActorLocation();
	const FVector Forward = GetActorForwardVector();
	DRAW_SPHERE_EVERY_FRAME(Location);
	DRAW_LINE_EVERY_FRAME(Location, Forward-Location);
}
