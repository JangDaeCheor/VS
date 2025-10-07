// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "VSDefaultGameStatus.h" // cpp에서 widget을 cast..
#include "VSDefaultCharacter.h"

#include "VSGameMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class VS_API UVSGameMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	class AVSDefaultGameStatus* currentState = nullptr;
	class AVSDefaultCharacter* currentCharacter = nullptr;

	UTextBlock* timeTextBlock = nullptr;
	UProgressBar* playerHealthBar = nullptr;

public:
	// 사용자 위젯이 생성될 때 나타나는 함수
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
};
