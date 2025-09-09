#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SkateCharacter.generated.h"

// Forward declarations
class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;
class UAnimInstance;

UCLASS()
class SKATEBOARDING_API ASkateCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASkateCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

   
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* SkateMesh;

   
    UPROPERTY(EditAnywhere, Category = "Movement")
    float BaseForwardSpeed = 600.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float BoostForwardSpeed = 1200.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float BoostDuration = 0.5f;

  
    UPROPERTY(EditAnywhere, Category = "Animations")
    UAnimMontage* IdleMontage;

    UPROPERTY(EditAnywhere, Category = "Animations")
    UAnimMontage* RunMontage;

    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* SkateMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* IA_Look;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* IA_Boost;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* IA_Jump;

private:
   
    void HandleLook(const FInputActionValue& Value);
    void HandleBoost();
    void HandleJump();
    void StopBoost();

    
    void PlayAnimationMontage(UAnimMontage* MontageToPlay);

    UPROPERTY()
    UAnimInstance* CachedAnimInstance;
};
