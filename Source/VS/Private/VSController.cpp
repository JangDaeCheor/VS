// Fill out your copyright notice in the Description page of Project Settings.


#include "VSController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "VSPauseWidget.h"

void AVSController::BeginPlay()
{
	// 원본의 BeginPlay
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	// 게임과 UI를 같이 사용
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
};

void AVSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVSController::InputMove);
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &AVSController::InputPause);
	}
};

void AVSController::InputMove(const FInputActionValue& value)
{
	FVector2D inputAxis = value.Get<FVector2D>(); // 아무 설정도 하지 않을 시 1, 0

	// FString text = FString::Printf(TEXT("%f, %f"), inputAxis.X, inputAxis.Y);
	// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Black, text);

	if (ACharacter* controlledCharacter = GetCharacter())
	{
		controlledCharacter->GetMovementComponent()->AddInputVector(FVector(inputAxis.Y, inputAxis.X, 0));
	}
}

void AVSController::InputPause()
{
	// SetPause(IsPaused() == false);
	if (IsValid(PauseWidget))
	{
		if (IsValid(currentPause))
		{
			currentPause->RemoveFromParent();
			currentPause = nullptr;
		}
		else if (currentPause = CreateWidget(this, PauseWidget))
		{
			currentPause->AddToPlayerScreen(0);
		}
	}
}
