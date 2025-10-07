// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "VSDefaultGameStatus.generated.h"

enum GameClearState
{
	Play,
	Lose,
	Win
};
/**
 * 
 */

// 프로젝트 세팅 -> 프로젝트 -> 맵&모드 -> 선택된 게임 모드 -> 게임 스테이트 클래스
UCLASS()
class VS_API AVSDefaultGameStatus : public AGameStateBase
{
	GENERATED_BODY()

protected:
	class AVSDefaultCharacter* playerCharacter = nullptr;

	GameClearState currentState = GameClearState::Play;

	UPROPERTY(EditAnywhere, Category = "Play", meta = (AllowPrivateAccess = "true"))
	// float ClearTime = 300.f;
	float ClearTime = 30.f;
	float LeftTime;

	float Score;

	// 블루프린트 클래스. 위젯 블루프린트는 만든 위젯 클래스를 상속받는 클래스
	TSubclassOf<class UVSGameMainWidget> MainWidget;

	TSubclassOf<class UUserWidget> WinWidget;
	TSubclassOf<class UUserWidget> LoseWidget;

public:
	AVSDefaultGameStatus();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void WinGame();
	virtual void LoseGame();

public:
	virtual FString GetTimeString();

	void AddScore(float wantScore) {Score += wantScore;};
	float GetScore() {return Score;};
};
