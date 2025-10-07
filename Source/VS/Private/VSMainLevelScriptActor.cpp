// Fill out your copyright notice in the Description page of Project Settings.


#include "VSMainLevelScriptActor.h"
#include "Kismet/GameplayStatics.h" // 게임 플레이 관련 유틸리티를 모아둔 정적 함수 집합 클래스
#include "VSMainWidget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AVSMainLevelScriptActor::BeginPlay()
{
    Super::BeginPlay();

    if (IsValid(MainWidget))
    {
        if (UVSMainWidget* created = CastChecked<UVSMainWidget>(CreateWidget(GetWorld(), MainWidget)))
        {
            GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Black, TEXT("main widget"));
            created->AddToPlayerScreen();
        }
    }

    if (APlayerController* player = UGameplayStatics::GetPlayerController(GetWorld(), 0))
    {
        player->SetShowMouseCursor(true);

        // InputMode : 입력 모드 (GameAndUI, UIOnly, GameOnly)
        FInputModeGameAndUI inputMode;
        inputMode.SetHideCursorDuringCapture(false); // 클릭중에도 마우스 커서가 숨겨지지 않게
        player->SetInputMode(inputMode);
    }

}
