// Fill out your copyright notice in the Description page of Project Settings.


#include "VSMainWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UVSMainWidget::NativeConstruct()
{
    GameStartButton = CastChecked<UButton>(GetWidgetFromName(TEXT("GameStartButton")));
    GameQuitButton = CastChecked<UButton>(GetWidgetFromName(TEXT("GameQuitButton")));

    if (IsValid(GameStartButton))
    {
        GameStartButton->OnClicked.AddDynamic(this, &UVSMainWidget::GameStartClicked);
    }
    if (IsValid(GameQuitButton))
    {
        GameQuitButton->OnClicked.AddDynamic(this, &UVSMainWidget::GameQuitClicked);
    }
}

void UVSMainWidget::NativeTick(const FGeometry &MyGeometry, float DeltaTime)
{
}

void UVSMainWidget::GameStartClicked()
{
    // 클릭시 레벨 변경
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("InGame"));
}

void UVSMainWidget::GameQuitClicked()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Type::Quit, true);
}
