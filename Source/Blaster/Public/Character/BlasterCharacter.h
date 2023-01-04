// CopyRight Blaster Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"

UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Move forward (1.0) and backward (-1.0). */
	void MoveForward(float Value);

	/** Move right (1.0) and left (-1.0). */
	void MoveRight(float Value);

	/** Turn camera boom right (1.0) and left (-1.0). */
	void Turn(float Value);

	/** Turn camera boom up (1.0) and down (-1.0). */
	void LookUp(float Value);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	/** Arm that takes the camera for third person view effect. */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	/** Camera that renders what character see. */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;
	
};
