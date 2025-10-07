// Fill out your copyright notice in the Description page of Project Settings.


#include "VSPauseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UVSPauseWidget::NativeConstruct()
{
    PlayAnimation(StartPauseAnimation);

    UGameplayStatics::SetGamePaused(GetWorld(), true);

    ResumeButton = CastChecked<UButton>(GetWidgetFromName(TEXT("ResumeButton")));
    MainButton = CastChecked<UButton>(GetWidgetFromName(TEXT("MainButton")));

    if (IsValid(ResumeButton))
    {
        ResumeButton->OnClicked.AddDynamic(this, &UVSPauseWidget::OnResumeClicked);
    }
    if (IsValid(MainButton))
    {
        MainButton->OnClicked.AddDynamic(this, &UVSPauseWidget::OnMainClicked);
    }
}

void UVSPauseWidget::NativeDestruct()
{
    UGameplayStatics::SetGamePaused(GetWorld(), false);

    // 게임 시간 조절
    // UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.5f);
}

void UVSPauseWidget::OnResumeClicked()
{
    RemoveFromParent();
}

void UVSPauseWidget::OnMainClicked()
{
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuLevel"));
}
