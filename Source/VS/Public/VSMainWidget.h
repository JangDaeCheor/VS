// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VSMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class VS_API UVSMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	class UButton* GameStartButton = nullptr;
	class UButton* GameQuitButton = nullptr;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	UFUNCTION()
	virtual void GameStartClicked();
	UFUNCTION()
	virtual void GameQuitClicked();
};
