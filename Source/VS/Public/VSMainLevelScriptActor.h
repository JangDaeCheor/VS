// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "VSMainLevelScriptActor.generated.h"

/**
 * 
 */
// MainMenuLevel의 레벨 스크립트 상속
UCLASS()
class VS_API AVSMainLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> MainWidget;
	
protected:
	virtual void BeginPlay() override;
};
