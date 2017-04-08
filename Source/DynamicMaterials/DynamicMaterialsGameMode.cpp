// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DynamicMaterials.h"
#include "DynamicMaterialsGameMode.h"
#include "DynamicMaterialsHUD.h"
#include "DynamicMaterialsCharacter.h"

ADynamicMaterialsGameMode::ADynamicMaterialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADynamicMaterialsHUD::StaticClass();
}
