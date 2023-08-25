
#include "Pawns/Birds.h"
#include "Components/CapsuleComponent.h"

ABirds::ABirds(): APawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Root=CreateDefaultSubobject<UCapsuleComponent>( TEXT("Root"));
	SetRootComponent(Root);

	Bird = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Birld"));
	Bird->SetupAttachment(GetRootComponent());

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ABirds::BeginPlay()
{
	Super::BeginPlay();
}

void ABirds::MoveForward(float Value)
{
	if(!Controller||Value==0) return;

	const FVector Forward =GetActorForwardVector();
	AddMovementInput(Forward,Value);
}

void ABirds::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ABirds::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ABirds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABirds::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->
		BindAxis(FName("MoveForward"),this,&ABirds::MoveForward);

	bUseControllerRotationYaw=true;
	PlayerInputComponent->
		BindAxis(FName("Turn"),this,&ABirds::Turn);

	bUseControllerRotationPitch=true;
	PlayerInputComponent->
		BindAxis(FName("LookUp"),this,&ABirds::LookUp);
}
