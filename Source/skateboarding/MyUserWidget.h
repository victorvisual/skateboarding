#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MyUserWidget.generated.h"

UCLASS()
class SKATEBOARDING_API UMyUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
   
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateScore(int32 NewScore);

protected:
    
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreText;
};
