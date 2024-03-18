// Fill out your copyright notice in the Description page of Project Settings.


#include "GasProjectAttributeSet.h"
#include "Net/UnrealNetwork.h"

UGasProjectAttributeSet::UGasProjectAttributeSet()
	: Health(40.0f), MaxHealth(60.0f)
{
}

void UGasProjectAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGasProjectAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGasProjectAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}


void UGasProjectAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGasProjectAttributeSet, Health, OldHealth);
}

void UGasProjectAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGasProjectAttributeSet, MaxHealth, OldMaxHealth);
}

void UGasProjectAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UGasProjectAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UGasProjectAttributeSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
}
