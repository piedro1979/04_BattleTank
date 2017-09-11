// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);
		

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO limit firing rate
	}
}

