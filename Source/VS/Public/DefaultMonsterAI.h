// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DefaultMonsterAI.generated.h"

/**
 * 
 */
UCLASS()
class VS_API ADefaultMonsterAI : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	float AttackRange = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	float AttackDamage = 100.0f;

public:
	ADefaultMonsterAI();
	
protected:
	virtual void Tick(float DeltaSeconds) override;

};
