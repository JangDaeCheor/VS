// Copyright Epic Games, Inc. All Rights Reserved.

#include "VSGameMode.h"
#include "VSPlayerController.h"
#include "VSCharacter.h"

#include "VSDefaultGameStatus.h"

#include "UObject/ConstructorHelpers.h"

AVSGameMode::AVSGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AVSPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	//static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/VS/Blueprints/BP_Controller"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	GameStateClass = AVSDefaultGameStatus::StaticClass();
}