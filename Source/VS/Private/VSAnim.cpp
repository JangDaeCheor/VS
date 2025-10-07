// Fill out your copyright notice in the Description page of Project Settings.


#include "VSAnim.h"
// Pawn : 이동 능력이 없는 캐릭터(걷기나 뛰기같은) + MovementComponent = Character
#include "GameFramework/PawnMovementComponent.h"

void UVSAnim::NativeUpdateAnimation(float DeltaSeconds)
{
    if (APawn* owner = TryGetPawnOwner())
    {
        if (UPawnMovementComponent* movement = owner->GetMovementComponent())
        {
            speed = movement->Velocity.Size2D();
            isJump = movement->IsFalling();
        }
    }
}
