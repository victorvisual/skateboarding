#include "SkateGameModeBase.h"
#include "SkateCharacter.h"
#include "SkatePlayerController.h"
#include "GameManager.h"
#include "Kismet/GameplayStatics.h"

ASkateGameModeBase::ASkateGameModeBase()
{
    DefaultPawnClass = ASkateCharacter::StaticClass();
    PlayerControllerClass = ASkatePlayerController::StaticClass();
}

void ASkateGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    if (UWorld* World = GetWorld())
    {
        World->SpawnActor<AGameManager>(AGameManager::StaticClass());
    }
}
