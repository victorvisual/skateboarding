#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ScoreWidgetCPP.generated.h"

UCLASS()
class SKATEBOARDING_API UScoreWidgetCPP : public UUserWidget
{
    GENERATED_BODY()

public:
  
    UFUNCTION(BlueprintCallable)
    void UpdateScore(int NewScore);

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreText;
};
