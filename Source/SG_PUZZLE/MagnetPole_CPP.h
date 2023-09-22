// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagnetPole_CPP.generated.h"

UCLASS()
class SG_PUZZLE_API AMagnetPole_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagnetPole_CPP();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magnetism")
		bool mbIsNorthPole;  // True for North, False for South

		// Force applied on the poles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magnetism")
		float mMagneticForce;

	// Update function to apply magnetic interaction
	void ApplyMagneticForce(AMagnetPole_CPP* otherPole, float minInteractionDistance);
};
