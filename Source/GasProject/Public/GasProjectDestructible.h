// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GasProjectAttributeSet.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "GasProjectDestructible.generated.h"

UCLASS()
class GASPROJECT_API AGasProjectDestructible : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UGasProjectAttributeSet* AttributeSet;

public:	
	// Sets default values for this actor's properties
	AGasProjectDestructible();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthChanged(float OldValue, float NewValue);

};
