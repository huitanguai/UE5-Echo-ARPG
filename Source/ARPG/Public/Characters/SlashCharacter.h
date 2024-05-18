// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
#include "SlashCharacter.generated.h"


UCLASS()
class ARPG_API ASlashCharacter : public ABaseCharacter,public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void SetOverlappingItem(class AItem* Item) override;
	virtual void AddGold(class ATreasure* Treasure) override;
	virtual void AddSouls(class ASoul* Soul) override;

protected:
	virtual void BeginPlay() override;

	/** 用于绑定操作映射的函数 */
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();
	virtual void Attack() override;
	virtual void Jump() override;
	void Dodge();
	/** 用于绑定操作映射的函数 */

	/** Combat */
	void EquipWeapon(AWeapon* Weapon);
	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	virtual bool CanAttack() override;
	bool CanDisarm();
	bool Canarm();
	void DisArm();
	void Arm();
	bool HasEnoughStamina();
	bool IsOccupied();
	/** Combat */

	void PlayEquipMontage(const FName& SectionName);
	virtual int32 PlayAttackMontage() override;
	virtual void Die() override;
	virtual void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName) override;

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UCameraComponent* ViewCamera;

private:
	bool IsUnoccupied();
	void InitializeSlashOverlay();
	void SetHUDHealth();
	

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere,Category = "Hair")
	class UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere,Category = "Hair")
	class UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	class AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	class UAnimMontage* EquipMontage;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	class USlashOverlay* SlashOverlay;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
