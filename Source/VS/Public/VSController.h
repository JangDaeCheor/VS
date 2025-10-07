// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VSController.generated.h"

/**
 * 
 */
UCLASS()
class VS_API AVSController : public APlayerController
{
	GENERATED_BODY()
	
	// BlueprintReadOnly / BlueprintWriteOnly / BlueprintReadWrite
	// UBT와 UHT는 옵션을 파싱할 때 순서에 상관없이 해석
	// EditAnywhere : 에디터의 모든 곳에서 수정 가능
	// Category = Input : Input 카테고리로 묶임
	// meta = (AllowPrivateAccess = "true") : 비공개 변수이지만 UPROPERTY로 접근 가능하게 허용
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PauseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Widget, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUserWidget> PauseWidget;

	TObjectPtr<class UUserWidget> currentPause = nullptr;

protected:
	// 게임이 시작하는 BeginPlay
	virtual void BeginPlay() override;
	// 입력을 준비하는 함수
	virtual void SetupInputComponent() override;

	// 움직이라는 명령 받음
	UFUNCTION()
	virtual void InputMove(const FInputActionValue& value);

	UFUNCTION()
	virtual void InputPause();
};
