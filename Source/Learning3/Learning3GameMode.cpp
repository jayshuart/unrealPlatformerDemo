// Copyright Epic Games, Inc. All Rights Reserved.

#include "Learning3GameMode.h"
#include "Learning3Character.h"
#include "UObject/ConstructorHelpers.h"

ALearning3GameMode::ALearning3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
