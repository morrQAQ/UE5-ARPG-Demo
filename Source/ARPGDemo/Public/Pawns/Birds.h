
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Birds.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;


UCLASS()
class ARPGDEMO_API ABirds : public APawn
{
	GENERATED_BODY()

public:
	ABirds();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Bird;
	
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Root;

	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);

};
