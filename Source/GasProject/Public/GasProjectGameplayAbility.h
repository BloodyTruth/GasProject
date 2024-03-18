// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../GasProject.h"
#include "GasProjectGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGasProjectGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputID { EAbilityInputID::None };
	
};
