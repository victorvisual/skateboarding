#include "GameManager.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidgetCPP.h" 

AGameManager::AGameManager()
{
    PrimaryActorTick.bCanEverTick = false;
    Score = 0;
    ScoreWidgetInstance = nullptr;
}

void AGameManager::BeginPlay()
{
    Super::BeginPlay();

   
    if (ScoreWidgetClass)
    {
        
        ScoreWidgetInstance = CreateWidget<UScoreWidgetCPP>(GetWorld(), ScoreWidgetClass);
        if (ScoreWidgetInstance)
        {
            ScoreWidgetInstance->AddToViewport();
         
            ScoreWidgetInstance->UpdateScore(Score);
        }
    }
}

void AGameManager::AddScore(int32 Value)
{
    Score += Value;

  
    if (ScoreWidgetInstance)
    {
        ScoreWidgetInstance->UpdateScore(Score);
    }
}
