#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

class UItemDefinition;

/**
*	Defines the type of the item.
*/
UENUM()
enum class EItemType : uint8
{
	Tool UMETA(DisplayName = "Tool"),
	Consumable UMETA(DisplayName = "Consumable")
};

/**
*	Contains textual data about the item.
*/
USTRUCT(BlueprintType)
struct FItemText
{
	GENERATED_BODY()

	// The text name of the item.
	UPROPERTY(EditAnywhere)
	FText Name;

	// The text description of the item.
	UPROPERTY(EditAnywhere)
	FText Description;
};

/**
*	Defines a basic item that can be used in a data table.
*/
USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType ItemType;

	// The ID name of this item for referencing in a table row.
	// 然后把FName放在后面！
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ID;
	// Text struct including the item name and description.
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemText ItemText;

	// The Data Asset item definition associated with this item.
	UPROPERTY(EditAnywhere, Category = "Item Data")
	TObjectPtr<UItemDefinition> ItemBase;
};