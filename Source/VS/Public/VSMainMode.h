// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VSMainMode.generated.h"

/**
 * 
 */
// MainMenuLevel에서 DefaultPawnClass를 없애기 위해 만듬.
UCLASS()
class VS_API AVSMainMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AVSMainMode();
};
