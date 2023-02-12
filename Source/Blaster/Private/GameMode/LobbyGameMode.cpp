// CopyRight Blaster Game. All Rights Reserved.


#include "GameMode/LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if (NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			bUseSeamlessTravel = true;
			
			// Load a map for all clients that exist on server as listen server
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}

