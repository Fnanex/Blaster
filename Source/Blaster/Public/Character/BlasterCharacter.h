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

	/** Move forward and backward. */
	void MoveForward(float Value);

	/** Move right and left. */
	void MoveRight(float Value);

	/** Turn camera boom right and left. */
	void Turn(float Value);

	/** Turn camera boom up and down. */
	void LookUp(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called when this object begins replicating to initialize the state of custom property conditions. */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
private:
	/** Arm that takes the camera for third person view effect. */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	/** Camera that renders what character see. */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;

	/** Overhead widget to spawn. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	class UWidgetComponent* OverheadWidget;

	/** Weapon that takes character in hands. */
	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	class AWeapon* OverlappingWeapon;
	
	/** On replicate overlapping weapon for owner client. */
	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);

public:
	/** Set new overlapping weapon. */
	void SetOverlappingWeapon(AWeapon* Weapon);

};
