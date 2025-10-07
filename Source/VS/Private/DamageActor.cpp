// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageActor.h"
#include "Engine/DamageEvents.h"
#include "NiagaraFunctionLibrary.h"

#include "Camera/CameraShakeBase.h"
#include "Kismet/GameplayStatics.h"// 게임 플레이 관련 유틸리티를 모아둔 정적 함수 집합 클래스

#include "VSDefaultCharacter.h"

// Sets default values
ADamageActor::ADamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADamageActor::NotifyHit
(
	UPrimitiveComponent *MyComp, 
	AActor *Other, 
	UPrimitiveComponent *OtherComp, 
	bool bSelfMoved, 
	FVector HitLocation, 
	FVector HitNormal, 
	FVector NormalImpulse, 
	const FHitResult &Hit
)
{
	if (IsValid(Other))
	{
		// FDamageEvent;           일반적 데미지
		// FPointDamageEvent;      국소적인 데미지
		// FRadialDamageEvent;     방사형 데미지

		//EventInstigator 공격을 시킨 컨트롤러
		AController* instigator = nullptr;
		// 액터끼리도 소유자가 존재함
		if (Owner)
		{
			instigator = Owner->GetInstigatorController();
		}

		if (AVSDefaultCharacter* enemy = Cast<AVSDefaultCharacter>(Other))
		{
			// GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Black, TEXT("eneym"));

			if (Other->TakeDamage(Damage, FDamageEvent(), instigator, this) > 0)
			{
				if (APlayerController* asPlayer = UGameplayStatics::GetPlayerController(GetWorld(), 0))
				{
					asPlayer->ClientStartCameraShake(Shake);
				}

				// At Location : 해당 위치에 고정
				// Attached : 해당 컴포넌트에 붙임.
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, GetActorLocation());
				Destroy(); // 액터 파괴
			}
		}
	}
};
