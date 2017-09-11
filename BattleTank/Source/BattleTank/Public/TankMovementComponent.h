// Copyright Pdro Ltd. 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible from driving the tank tracks
 */ 
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float Throw);

private:
	// called from the pathfinding logic by the AI Controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
