// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicMaterials.h"
#include "Dynamic_Cube.h"


// Sets default values
ADynamic_Cube::ADynamic_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CubeRoot"));
	RootComponent = CubeRoot;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	CubeTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("CubeTrigger"));
	CubeTrigger->bGenerateOverlapEvents = true;
	CubeTrigger->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	CubeTrigger->OnComponentBeginOverlap.AddDynamic(this, &ADynamic_Cube::OnPlayerTriggerRust);
	CubeTrigger->OnComponentEndOverlap.AddDynamic(this, &ADynamic_Cube::OnPlayerExitRust);
	CubeTrigger->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	RustAmount = 1.0f;
}

// Called when the game starts or when spawned
void ADynamic_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADynamic_Cube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRustEffectTriggered)
	{
		if (RustAmount > 0.0f)
		{
			RustAmount -= DeltaTime;
		}
	}

	if (!bRustEffectTriggered)
	{
		if (RustAmount < 1.0f)
		{
			RustAmount += DeltaTime;
		}
	}

	UMaterialInstanceDynamic* RustMaterialInstance = CubeMesh->CreateDynamicMaterialInstance(0);

	if (RustMaterialInstance != nullptr)
	{
		RustMaterialInstance->SetScalarParameterValue(FName("RustAmount"), RustAmount);
	}

}

void ADynamic_Cube::OnPlayerTriggerRust(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	bRustEffectTriggered = true;
}

void ADynamic_Cube::OnPlayerExitRust(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	bRustEffectTriggered = false;
}

