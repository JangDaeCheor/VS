// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultMonsterAI.h"
#include "GameFramework/PawnMovementComponent.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Engine/DamageEvents.h"

ADefaultMonsterAI::ADefaultMonsterAI()
{
    // Tick 이벤트 활성화.
    PrimaryActorTick.bCanEverTick = true;
};

void ADefaultMonsterAI::Tick(float DeltaSeconds)
{
    if (APlayerController* asPlayer = GetWorld()->GetFirstPlayerController()) 
    {
        if (APawn* target = asPlayer->GetPawn())
        {
            // // 장애물이 있을시 부딪치고 돌아가지 않음.
            // if (UPawnMovementComponent* movement = GetPawn()->GetMovementComponent())
            // {
            //     //                          대상의 위치             제 캐릭터의 위치(바로 GetActorLocation을 하면 AIController의 위치)
            //     FVector direction = target->GetActorLocation() - GetPawn()->GetActorLocation();
            //     // normalize
            //     direction.Normalize();

            //     // 만들어준 방향으로 이동
            //     movement->AddInputVector(direction);
            // }
            
            // AcceptanceRadius : 액터에 일정 거리 다가가면 이동을 완료
            // bStopOnOverlap : AcceptanceRadius에 폰의 반경 추가
            // bUsePathFinding : 네비게이션 데이터를 사용하여 경로 계산
            // bCanStrafe : 포커스 관련 플래그 설정 (bAllowStrafe)
            // FilterClass : 경로 찾기 조정을 위한 탐색 필터. 지정하지 않을 시 DefaultNavigationFilterClass
            // bAllowPartialPath : 목표에 도달할 수 없을 때 불완전한 경로 사용
            MoveToActor(target, -1.f, true, true, true, DefaultNavigationFilterClass, true);
            // NavMesh를 벗어나면 움직이지 않음

            if (GetPawn()->GetDistanceTo(target) < AttackRange)
            {
                target->TakeDamage(AttackDamage * DeltaSeconds, FDamageEvent(), this, GetPawn());
            }
        } else 
        {
            // GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("none player"));
        }
    }
};
