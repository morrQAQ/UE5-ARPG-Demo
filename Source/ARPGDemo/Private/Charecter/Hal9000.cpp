// Fill out your copyright notice in the Description page of Project Settings.
#include "Charecter/Hal9000.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GroomComponent.h"

AHal9000::AHal9000()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch =false;
	bUseControllerRotationRoll=false;
	bUseControllerRotationYaw=false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	
	SpringArm=CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength=300.f;
	SpringArm->bUsePawnControlRotation=true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	Camera->SetupAttachment(SpringArm);

	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(GetMesh());
	FString name = "head";
	Hair->AttachmentName = name;
}

void AHal9000::BeginPlay()
{
	Super::BeginPlay();
}

void AHal9000::MoveForward(float Value) 
{
	if(!Controller || Value==0) return;;
	
	//youtube video version.
	const FRotator ControlRotation (0.f,GetControlRotation().Yaw,0.f);
	const FVector Direction = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);
	
	// my direction version.
	// const FVector Forward =SpringArm->GetForwardVector();
	AddMovementInput(Direction,Value);
}

void AHal9000::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AHal9000::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AHal9000::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHal9000::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent  ->
	BindAxis(FName("MoveForward"),this,&AHal9000::MoveForward);

	PlayerInputComponent->
	BindAxis(FName("Turn"),this,&AHal9000::Turn);

	PlayerInputComponent->
	BindAxis(FName("LookUp"),this,&AHal9000::LookUp);
}



