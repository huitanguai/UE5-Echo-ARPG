// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"


UCLASS()
class ARPG_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

protected:
	//
	//用于绑定操作映射
	//
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();
	void Attack();

	//
	//用于播放montage
	//
	void PlayAttackMontage();
	void PlayEquipMontage(const FName& SectionName);

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	bool CanAttack();
	bool CanDisarm();
	bool Canarm();

	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite,meta=(AllowPrivateAccess="true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere,Category = "Hair")
	class UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere,Category = "Hair")
	class UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	class AItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere,Category="Weapon")
	class AWeapon* EquippedWeapon;

	//
	//montage
	//
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	class UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	class UAnimMontage* EquipMontage;



public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() { return CharacterState; }
};
