// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakableActor.generated.h"

UCLASS()
class ARPG_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakableActor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere , Category="Breakable Properties")
	TArray<TSubclassOf<class ATreasure>> TreasureClasses;

private:
	bool bBroken = false;
};
