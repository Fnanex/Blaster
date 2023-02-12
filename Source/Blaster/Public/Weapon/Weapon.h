// CopyRight Blaster Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

/**
 * Weapon state, i.g equipped/dropped and others.
 */
UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	/** Weapon is'nt picked yet. */
	EWS_Initial UMETA(DisplayName = "Initial State"),

	/** Weapon is actually equipped by character. */
	EWS_Equipped UMETA(DisplayName = "Equiped"),

	/** Weapon picked before and dropped now. */
	EWS_Dropped UMETA(DisplayName = "Dropped"),
	
	/** Default MAX. */
	EWS_MAX UMETA(DisplayName = "Default MAX")
};

/**
 * Base weapon class that player can pickup.
 */
UCLASS()
class BLASTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** On area sphere overlaps. */
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* PrimitiveComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	/** This weapon mesh. */
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	USkeletalMeshComponent* WeaponMesh;

	/** Weapon mesh area sphere, can be used for pickup system. */
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class USphereComponent* AreaSphere;

	/** This weapon current state. */
	UPROPERTY(VisibleAnywhere)
	EWeaponState WeaponState;

	/** Pick up widget text to spawn. */
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class UWidgetComponent* PickupWidget;
	
};
