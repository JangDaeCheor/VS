// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponBaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VS_API UWeaponBaseComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 공격의 쿨타임
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown", meta = (AllowPrivateAccess = "true"))
	float Cooldown;
	// 마지막으로 공격한 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooldown", meta = (AllowPrivateAccess = "true"))
	float LastShotTime;

public:	
	// Sets default values for this component's properties
	UWeaponBaseComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// 공격 함수
	UFUNCTION()
	virtual void Attack();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
