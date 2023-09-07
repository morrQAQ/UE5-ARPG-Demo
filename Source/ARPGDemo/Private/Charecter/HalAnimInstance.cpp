#include "Charecter/HalAnimInstance.h"
#include "Charecter/Hal9000.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UHalAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Hal9000 = Cast<AHal9000>(TryGetPawnOwner());

	if (!Hal9000) { return; }

	Movement = Hal9000->GetCharacterMovement();
}

void UHalAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!Movement) { return; }

	GroundSpeed = UKismetMathLibrary::VSizeXY(Movement->Velocity);
	IsFalling = Movement->IsFalling();
}
