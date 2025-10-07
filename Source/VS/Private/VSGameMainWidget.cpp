// Fill out your copyright notice in the Description page of Project Settings.


#include "VSGameMainWidget.h"


void UVSGameMainWidget::NativeConstruct()
{
    UUserWidget::NativeConstruct();

    timeTextBlock = CastChecked<UTextBlock>(GetWidgetFromName(TEXT("TimeTextBlock")));
    playerHealthBar = CastChecked<UProgressBar>(GetWidgetFromName(TEXT("HealthBar")));
}

void UVSGameMainWidget::NativeTick(const FGeometry &MyGeometry, float DeltaTime)
{
    UUserWidget::NativeTick(MyGeometry, DeltaTime);

    if (IsValid(timeTextBlock) && IsValid(currentState))
    {
        timeTextBlock->SetText(FText::FromString(currentState->GetTimeString()));
    }

    if (IsValid(playerHealthBar) && IsValid(currentCharacter))
    {
        playerHealthBar->SetPercent(currentCharacter->GetHealthRate());
    }
}
