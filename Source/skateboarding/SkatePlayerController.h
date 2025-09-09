#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SkatePlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class SKATEBOARDING_API ASkatePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	int32 MappingPriority = 0;
};
