// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBaseComponent.h"

// Sets default values for this component's properties
UWeaponBaseComponent::UWeaponBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	// 컴포넌트를 나중에 만드실 때 틱 이벤트가 필요 없으면 false로 맞추면 된다.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UWeaponBaseComponent::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Attacked"));
}

// Called when the game starts
void UWeaponBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 마지막 공격시간으로부터 쿨타임만큼 기다렸다고 한다면 공격할 수 있게
	// 현재 시간 >= 마지막 공격시간 + 쿨타임
	//					컴포넌트를 가진 액터->액터 생성 후 지난 게임 시간
	float currentTime = GetOwner()->GetGameTimeSinceCreation();

	if (currentTime >= LastShotTime + Cooldown)
	{
		Attack();
		// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Black, FString::FormatAsNumber(LastShotTime));
		// 공격 후에는 공격했다고 표현.
		LastShotTime = currentTime;
	}
}

