// Fill out your copyright notice in the Description page of Project Settings.


#include "VSDefaultGameStatus.h"

#include "VSGameMainWidget.h"
#include "Kismet/GameplayStatics.h" // 게임 플레이 관련 유틸리티를 모아둔 정적 함수 집합 클래스
#include "DefaultMonsterAI.h"
#include "Engine/DamageEvents.h"

AVSDefaultGameStatus::AVSDefaultGameStatus()
{
    PrimaryActorTick.bCanEverTick = true;
    ConstructorHelpers::FClassFinder<UVSGameMainWidget> mainWidgetFinder(TEXT("/Game/Widget/GameMainWidget"));
    if (mainWidgetFinder.Succeeded()) 
    {
        MainWidget = mainWidgetFinder.Class;
    }
    
    ConstructorHelpers::FClassFinder<UUserWidget> winWidgetFinder(TEXT("/Game/Widget/WinWidget"));
    if (winWidgetFinder.Succeeded()) 
    {
        WinWidget = winWidgetFinder.Class;
    }
    ConstructorHelpers::FClassFinder<UUserWidget> loseWidgetFinder(TEXT("/Game/Widget/LoseWidget"));
    if (loseWidgetFinder.Succeeded()) 
    {
        LoseWidget = loseWidgetFinder.Class;
    }
};

void AVSDefaultGameStatus::BeginPlay()
{
    LeftTime = ClearTime;
    playerCharacter = CastChecked<AVSDefaultCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (IsValid(MainWidget))
    {
        if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainWidget))
        {
            // 위젯은 인터페이스, 누구의 인터페이스인가
            // 어디에 붙일 것인가 확인
            created->AddToPlayerScreen(0);

            if (UVSGameMainWidget* asGameMain = CastChecked<UVSGameMainWidget>(created))
            {
                asGameMain->currentState = this;
                asGameMain->currentCharacter = playerCharacter;
            }
        }
    }
};

void AVSDefaultGameStatus::Tick(float DeltaSeconds)
{
    if (currentState == GameClearState::Play && LeftTime > 0)
    {
        LeftTime -= DeltaSeconds;
        Score += DeltaSeconds;

        if (LeftTime <= 0)
        {
            LeftTime = 0;
            WinGame();
        }

        if (IsValid(playerCharacter) == false || playerCharacter->GetHealthRate() <= 0)
        {
            LoseGame();
        }
    }
};

void AVSDefaultGameStatus::WinGame() 
{
    currentState = GameClearState::Win;

    if (IsValid(WinWidget))
    {
        if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), WinWidget))
        {
            // 위젯은 인터페이스, 누구의 인터페이스인가
            // 어디에 붙일 것인가 확인
            created->AddToPlayerScreen(0);
        }
    }

    TArray<AActor*> actors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADefaultMonsterAI::StaticClass(), actors);

    if (actors.Num() > 0) 
    {
        for(AActor* currentActor : actors)
        {
            if (ADefaultMonsterAI* asMonsterAI = CastChecked<ADefaultMonsterAI>(currentActor))
            {
                if (APawn* asPawn = asMonsterAI->GetPawn())
                {
                    asPawn->TakeDamage(FLT_MAX, FDamageEvent(), nullptr, nullptr);
                }
            }
        }
    }
};

void AVSDefaultGameStatus::LoseGame() 
{
    currentState = GameClearState::Lose;

    if (IsValid(LoseWidget))
    {
        if (UUserWidget* created = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), LoseWidget))
        {
            // 위젯은 인터페이스, 누구의 인터페이스인가
            // 어디에 붙일 것인가 확인
            created->AddToPlayerScreen(0);
        }
    }
};

FString AVSDefaultGameStatus::GetTimeString()
{
    // String : 마음대로 변환이 가능
    // Text : UI에 표시하기 위하여 쓸 수 있는 문자열
    // Name : 검색하기 위한 문자열 (대소문자 구분 X)
    int leftTimeAsInt = LeftTime;
    return FString::Printf(TEXT("%d : %d"), leftTimeAsInt / 60, leftTimeAsInt % 60);
};
