// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class VS_API UResultWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	class UTextBlock* ScoreTextBlock = nullptr;
	class UButton* MainMenuButton = nullptr;

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void OnMainMenuClicked();
};
