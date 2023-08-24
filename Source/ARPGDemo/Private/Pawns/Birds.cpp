// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "Pawns/Birds.h"

// Sets default values
ABirds::ABirds(): APawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule1=CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule1"));

	SetRootComponent(Capsule1);
}

// Called when the game starts or when spawned
void ABirds::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABirds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABirds::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
