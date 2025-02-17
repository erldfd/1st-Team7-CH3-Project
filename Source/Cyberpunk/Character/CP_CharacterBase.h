#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "CP_CharacterBase.generated.h"

UCLASS()
class CYBERPUNK_API ACP_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACP_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	UPROPERTY(VisibleAnywhere, Category = "CPCharacter")
	int32 Hp;

};
