// Fill out your copyright notice in the Description page of Project Settings.


#include "MagnetPole_CPP.h"

// Sets default values
AMagnetPole_CPP::AMagnetPole_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMagnetPole_CPP::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMagnetPole_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMagnetPole_CPP::ApplyMagneticForce(AMagnetPole_CPP* otherPole, float minInteractionDistance)
{
    FVector direction = otherPole->GetActorLocation() - GetActorLocation();
    float Distance = direction.Size();

    if (Distance < minInteractionDistance)
    {
        direction.Normalize();
        float force = mMagneticForce * otherPole->mMagneticForce / FMath::Pow(Distance, 2);

        if (mbIsNorthPole == otherPole->mbIsNorthPole)
        {
            force = -force;
        }

        FVector forceVector = force * direction;
        FHitResult hitResult;
        AddActorWorldOffset(forceVector, true, &hitResult);
        otherPole->AddActorWorldOffset(-forceVector, true, &hitResult);
    }
}
