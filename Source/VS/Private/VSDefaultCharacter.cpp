// Fill out your copyright notice in the Description page of Project Settings.


#include "VSDefaultCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AVSDefaultCharacter::AVSDefaultCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void AVSDefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVSDefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVSDefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AVSDefaultCharacter::TakeDamage
(
	float DamageAmount, 
	FDamageEvent const &DamageEvent, 
	AController *EventInstigator, 
	AActor *DamageCauser
)
{
	//Event Instigator : 공격을 지시한 컨트롤러
	//저랑 비교했을 때 같은 컨트롤러 = 제 공격 => 데미지를 맞지 않음
	if (IsValid(EventInstigator) && EventInstigator == GetController())
	{
		return 0;
	}

	//Primitive Component 실체가 있는 컴포넌트
	//Skeletal Mesh 스켈레톤이 들어있는 메시
	// -> Add Force

	//Movement Component 이동 컴포넌트
	// -> Launch Character
	LaunchCharacter(FVector::UpVector * 200.0f, false, true);

	PlayAnimMontage(DamageMontage);

	healthCurrent -= DamageAmount;

	if (healthCurrent <= 0)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), deathEffect, GetActorLocation(), GetActorRotation(), GetActorScale());
		Destroy();
	}

    return DamageAmount;
}
