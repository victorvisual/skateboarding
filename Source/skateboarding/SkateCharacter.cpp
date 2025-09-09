#include "SkateCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "TimerManager.h"

ASkateCharacter::ASkateCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

   
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
    GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 350.f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    SkateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkateMesh"));
    SkateMesh->SetupAttachment(GetMesh());
    SkateMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    CachedAnimInstance = nullptr;
}

void ASkateCharacter::BeginPlay()
{
    Super::BeginPlay();

   
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(SkateMappingContext, 0);
        }
    }
    GetCharacterMovement()->MaxWalkSpeed = BaseForwardSpeed;

    
    CachedAnimInstance = GetMesh()->GetAnimInstance();


    PlayAnimationMontage(IdleMontage);
}

void ASkateCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AddMovementInput(GetActorForwardVector(), 1.0f);
}

void ASkateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ASkateCharacter::HandleLook);
        EnhancedInput->BindAction(IA_Boost, ETriggerEvent::Started, this, &ASkateCharacter::HandleBoost);
        EnhancedInput->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ASkateCharacter::HandleJump);
    }
}



void ASkateCharacter::HandleLook(const FInputActionValue& Value)
{
    const FVector2D LookAxisVector = Value.Get<FVector2D>();
    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(LookAxisVector.Y);
}

void ASkateCharacter::HandleBoost()
{
    GetCharacterMovement()->MaxWalkSpeed = BoostForwardSpeed;
    PlayAnimationMontage(RunMontage); 
    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(UnusedHandle, this, &ASkateCharacter::StopBoost, BoostDuration, false);
}

void ASkateCharacter::StopBoost()
{
    GetCharacterMovement()->MaxWalkSpeed = BaseForwardSpeed;
    PlayAnimationMontage(IdleMontage); 
}

void ASkateCharacter::HandleJump()
{
    Jump();
}



void ASkateCharacter::PlayAnimationMontage(UAnimMontage* MontageToPlay)
{
    
    if (CachedAnimInstance && MontageToPlay)
    {
       
        CachedAnimInstance->Montage_Stop(0.25f);

       
        CachedAnimInstance->Montage_Play(MontageToPlay, 1.0f);
    }
}
