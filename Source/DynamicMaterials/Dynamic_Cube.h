// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Dynamic_Cube.generated.h"

UCLASS()
class DYNAMICMATERIALS_API ADynamic_Cube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamic_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Dummy root compnent for the cube
	UPROPERTY(EditAnywhere)
		USceneComponent* CubeRoot;

	// The mesh for the cube
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CubeMesh;

	// The trigger mesh for the rust effect
	UPROPERTY(EditAnywhere)
		UBoxComponent* CubeTrigger;

private:

	// Has the player entered the trigger
	bool bRustEffectTriggered;

	// Storing the rust amount
	float RustAmount;
	
	// The function called when the player triggers the rusting effect
	UFUNCTION()
		void OnPlayerTriggerRust(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// The function calles when the player walks out of the trigger radius for the rust effect
	UFUNCTION()
		void  OnPlayerExitRust(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
