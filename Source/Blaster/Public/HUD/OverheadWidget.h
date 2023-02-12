// CopyRight Blaster Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Overhead display text, name and remote role. */ 
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DisplayText;

	/** Set player display name to selected string. */
	void SetDisplayText(FString TextToDisplay);

	/** Show controlling player net role. */
	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);
	
	/** Show controlling player name. */
	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APawn* InPawn);
	
protected:
	/** Call-back event for on level removed from world. */
	virtual void NativeDestruct() override;
	
};
