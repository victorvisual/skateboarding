// Obstacle.cpp (CORRIGIDO)

#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameManager.h" // Inclua o GameManager para poder usá-lo
#include "SkateCharacter.h" // Inclua o personagem para verificar se foi ele que colidiu
#include "Kismet/GameplayStatics.h"

AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = false;
    bHasScored = false;

    
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent; 

    
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(RootComponent); 
    TriggerBox->SetCollisionProfileName("Trigger"); 
    TriggerBox->SetBoxExtent(FVector(64.f, 64.f, 64.f)); 

    
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnOverlapBegin);
}

void AObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
    if (bHasScored || !Cast<ASkateCharacter>(OtherActor))
    {
        return;
    }

    
    AGameManager* GM = Cast<AGameManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameManager::StaticClass()));

    if (GM)
    {
    
        GM->AddScore(10); 
        bHasScored = true; 

        
    }
}
