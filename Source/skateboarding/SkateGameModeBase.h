#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkateGameModeBase.generated.h"

UCLASS()
class SKATEBOARDING_API ASkateGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASkateGameModeBase();

protected:
    virtual void BeginPlay() override;
};
