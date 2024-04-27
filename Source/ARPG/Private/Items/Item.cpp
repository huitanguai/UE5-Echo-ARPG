

#include "Items/Item.h"
#include "ARPG/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Characters/SlashCharacter.h"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(FName("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3 : %d"), AvgInt);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeComstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeComstant);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = FString("OtherActor = ") + OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Cyan, OtherActorName);
	}

	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter )
	{
		SlashCharacter->SetOverlappingItem(this);
	}
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString Self = FString("Self = ") + OverlappedComponent->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Blue, Self);
	}

	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(nullptr);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	if (ItemState==EItemState::EIS_Hovering)
	{
		AddActorWorldOffset(FVector(0.f, 0.f, TransformedSin()));
	}	
}

