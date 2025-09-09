// Obstacle.h (CORRIGIDO)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

// Forward declaration para o componente de colisão
class UBoxComponent;

UCLASS()
class SKATEBOARDING_API AObstacle : public AActor
{
    GENERATED_BODY()

public:
    AObstacle();

protected:
   
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;

    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* TriggerBox;

 
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
   
    bool bHasScored;
};
