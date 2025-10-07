// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponFireball.h"

UWeaponFireball::UWeaponFireball()
{
    if (IsValid(fireball) == false) // (fireball == nullptr)
    {
        ConstructorHelpers::FClassFinder<AActor> findFireBall(TEXT("/Game/VS/Blueprints/Fireball"));

        if (findFireBall.Succeeded())
        {
            fireball = findFireBall.Class;
        }
    }
};
	
void UWeaponFireball::Attack()
{
    if (AActor* inst = GetWorld()->SpawnActor(fireball))
    {
        FVector forward = GetOwner()->GetActorForwardVector();
        inst->SetActorLocation(GetOwner()->GetActorLocation() + (forward * 100.0f), false, nullptr, ETeleportType::ResetPhysics);
        // inst->SetActorScale3D(FVector(0.3f, 0.3f, 0.3f));

        if (UPrimitiveComponent* primit = inst->GetComponentByClass<UPrimitiveComponent>())
        {
            primit->AddForce(forward * 100000.0f, NAME_None, true);
        }
    }
};
