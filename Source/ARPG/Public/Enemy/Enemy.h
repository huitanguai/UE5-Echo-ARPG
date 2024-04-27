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
	//���ڲ���montage�ĺ���
	//
	void PlayHitReactMontage(const FName& SectionName);

private:
	//
	//��Ҫ����ͼ�и�ֵ��montage����
	//
	UPROPERTY(EditDefaultsOnly,Category="Montage")
	class UAnimMontage* HitReactMontage;

public:	

};