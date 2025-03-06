#include "CP_Projectile.h"
#include "CP_Guns.h"


ACP_Projectile::ACP_Projectile()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
    CollisionComponent->InitSphereRadius(10.0f);
    CollisionComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));  // 충돌 설정
    RootComponent = CollisionComponent;

    NiagaraEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraEffect"));
    NiagaraEffect->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraSystem(TEXT("/Game/Gun_BluePrint/NS_bullet.NS_bullet"));
    if (NiagaraSystem.Succeeded())
    {
        NiagaraEffect->SetAsset(NiagaraSystem.Object);
    }

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 2000.f;
    ProjectileMovement->MaxSpeed = 2000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->ProjectileGravityScale = 0.0f;

    CollisionComponent->OnComponentHit.AddDynamic(this, &ACP_Projectile::OnHit);
}

void ACP_Projectile::BeginPlay()
{
    Super::BeginPlay();

    SetLifeSpan(1.0f);

    AActor* OwnerActor = GetOwner();

    if (!OwnerActor)
    {
        return;
    }

    if (OwnerActor->ActorHasTag("Player"))
    {
        CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
    }
    else if (OwnerActor->ActorHasTag("Enemy"))
    {
        CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
    }
}




// 발사 함수
void ACP_Projectile::LaunchProjectile(const FVector& LaunchDirection)
{
    if (ProjectileMovement)
    {
        // 발사 방향 설정
        FVector LaunchVelocity = LaunchDirection * 9000.f;
        ProjectileMovement->Velocity = LaunchVelocity;
        ProjectileMovement->Activate();

        UE_LOG(LogTemp, Warning, TEXT("fire: %s"), *LaunchDirection.ToString());
    }
}

void ACP_Projectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor != this && OtherActor != GetOwner())
    {
        AActor* OwnerActor = GetOwner();
        AController* OwnerController = nullptr;

        if (OwnerActor)
        {
            APawn* OwnerPawn = Cast<APawn>(OwnerActor);
            if (OwnerPawn)
            {
                OwnerController = OwnerPawn->GetController();
            }
        }

        UE_LOG(LogTemp, Warning, TEXT("[ACP_Projectile] Hit: %s, Location: %s, Bone: %s"),
            *OtherActor->GetName(),
            *Hit.ImpactPoint.ToString(),
            (Hit.BoneName.IsNone() ? TEXT("None") : *Hit.BoneName.ToString()));

        float TotalDamage = 10.0f;  // 기본값 10 (NPC)

        if (!bIsNPCProjectile)  
        {
            ACP_Guns* Gun = Cast<ACP_Guns>(OwnerActor);
            if (Gun)
            {
                TotalDamage = Gun->CalculateTotalDamage();
            }
        }

        if (TotalDamage > 0.0f)
        {
            UGameplayStatics::ApplyDamage(
                OtherActor,
                TotalDamage,
                OwnerController,
                this,
                UDamageType::StaticClass()
            );
        }

        // 프로젝타일 소멸
        Destroy();
    }
}


