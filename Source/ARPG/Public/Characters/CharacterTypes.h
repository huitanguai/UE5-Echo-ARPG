#pragma once

UENUM(BlueprintType)
enum class ECharacterState :uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-Handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped Two-Handed Weapon")
};

UENUM(BlueprintType)
enum class EActionState :uint8
{
	EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_EquippingWeapon UMETA(DisplayName = "EquippingWeapon")
};

UENUM(BlueprintType)
enum class EDeathPose :uint8
{
	EDS_Alive UMETA(DisplayName = "Alive"),
	EDS_Death1 UMETA(DisplayName = "Death1"),
	EDS_Death2 UMETA(DisplayName = "Death2"),
	EDS_Death3 UMETA(DisplayName = "Death3"),
	EDS_Death4 UMETA(DisplayName = "Death4"),
	EDS_Death5 UMETA(DisplayName = "Death5"),
	EDS_Death6 UMETA(DisplayName = "Death6")
};