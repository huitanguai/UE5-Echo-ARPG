// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

UCLASS()
class ARPG_API AEnemy : public ACharacter,public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit(const FVector& ImpactPoint) override;

	void DirectionalHitReact(const FVector& ImpactPoint);

protected:
	virtual void BeginPlay() override;

	//
	//用于播放montage的函数
	//
	void PlayHitReactMontage(const FName& SectionName);

private:
	//
	//需要在蓝图中赋值的montage变量
	//
	UPROPERTY(EditDefaultsOnly,Category="Montage")
	class UAnimMontage* HitReactMontage;

public:	

};
