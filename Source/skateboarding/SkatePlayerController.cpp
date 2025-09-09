#include "SkatePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"

void ASkatePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// --- enables the mouse ---
	bShowMouseCursor = false;
	bEnableClickEvents = false;
	bEnableMouseOverEvents = false;
	SetInputMode(FInputModeGameOnly());

	// --- Add Mapping Context ---
	if (ULocalPlayer* LP = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (DefaultMappingContext)
				Subsystem->AddMappingContext(DefaultMappingContext, MappingPriority);
			else
				UE_LOG(LogTemp, Warning, TEXT("SkatePlayerController: DefaultMappingContext não setado."));
		}
	}
}
