// Copyright Epic Games, Inc. All Rights Reserved.

#include "GasProjectGameMode.h"
#include "GasProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGasProjectGameMode::AGasProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
