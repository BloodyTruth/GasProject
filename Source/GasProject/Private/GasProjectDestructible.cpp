// Fill out your copyright notice in the Description page of Project Settings.


#include "GasProjectDestructible.h"
#include "AbilitySystemComponent.h"
#include "GasProjectAttributeSet.h"

// Sets default values
AGasProjectDestructible::AGasProjectDestructible()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetCollisionObjectType(ECC_PhysicsBody);
	RootComponent = StaticMeshComponent;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGasProjectAttributeSet>("AttributeSet");
}

// Called when the game starts or when spawned
void AGasProjectDestructible::BeginPlay()
{
	Super::BeginPlay();

	if (!AbilitySystemComponent)
	{
		return;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AGasProjectDestructible::OnHealthAttributeChanged);
}

UAbilitySystemComponent* AGasProjectDestructible::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGasProjectDestructible::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

