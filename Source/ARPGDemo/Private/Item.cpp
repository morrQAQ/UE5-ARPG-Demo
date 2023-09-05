#include "Item.h"
#include "Components/SphereComponent.h"

AItem::AItem(): AActor()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnEndOverlap);
}

float AItem::TransformedSin() const { return Amplitude * FMath::Sin(RunningTime * TimeConstant); }

float AItem::TransformedCos() const { return Amplitude * FMath::Cos(RunningTime * TimeConstant); }

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                            const FHitResult& SweepResult)
{
	if (GEngine)
	{
		const FString OtherName = OtherActor->GetName();
		const FString Output = FString::Printf(TEXT("%s is overlapped!"), *OtherName);
		GEngine->AddOnScreenDebugMessage(0, 60.f, FColor::Black, Output);
	}
}

void AItem::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                         int32 OtherBodyIndex)
{
	if (GEngine)
	{
		const FString OtherName = OtherActor->GetName();
		const FString Output = FString::Printf(TEXT("%s is end ~~"), *OtherName);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Orange, Output);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
}
