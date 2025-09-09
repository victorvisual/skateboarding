#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

class UScoreWidgetCPP; // Forward declaration

UCLASS()
class SKATEBOARDING_API AGameManager : public AActor
{
    GENERATED_BODY()

public:
    AGameManager();

 
    UFUNCTION(BlueprintCallable, Category = "GameManager")
    void AddScore(int32 Value);

protected:
    virtual void BeginPlay() override;

    
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UScoreWidgetCPP> ScoreWidgetClass;

private:
    int32 Score;

   
    UPROPERTY()
    UScoreWidgetCPP* ScoreWidgetInstance;
};
