// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VSPauseWidget.generated.h"

/**
 * 
 */
UCLASS()
class VS_API UVSPauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	class UButton* ResumeButton = nullptr;
	class UButton* MainButton = nullptr;

protected:
	// BindWidgetAnim(StartPauseAnimation) : 같은 이름의 애님 바인드
	// Transient : 직렬화 해제
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* StartPauseAnimation;
	
protected:
	// 생성자
	virtual void NativeConstruct() override;
	// 소멸자
	virtual void NativeDestruct() override;

public:
	UFUNCTION()
	virtual void OnResumeClicked();
	UFUNCTION()
	virtual void OnMainClicked();
};
