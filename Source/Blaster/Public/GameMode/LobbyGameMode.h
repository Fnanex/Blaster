// CopyRight Blaster Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API ALobbyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	/**
	 * Called after a successful login.
	 * This is the first place it is safe to call replicated functions on the PlayerController.
	 */
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
