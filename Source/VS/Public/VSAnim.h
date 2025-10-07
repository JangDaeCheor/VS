// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "VSAnim.generated.h"

/**
 * 
 */
// blend space : 캐릭터 애니메이션을 상황에 맞게 자연스럽게 섞어서 재생하기 위한 애니메이션 에셋
//      -> LocoMotion
UCLASS()
class VS_API UVSAnim : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool isJump;
	// 애니메이션을 계산할 때에 UpdateAnimation이라는 함수가 나타나게 됩니다.
	// c++용으로 구성된 함수는 NativeUpdateAnimation 합니다.

public:
	void NativeUpdateAnimation(float DeltaSeconds) override;
};
