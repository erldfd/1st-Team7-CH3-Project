#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CP_Item.h"
#include "CP_Gear.generated.h"

UCLASS()
class CYBERPUNK_API ACP_Gear : public AActor, public ICP_Item
{
    GENERATED_BODY()

public:
    ACP_Gear();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* GearMesh;
};
