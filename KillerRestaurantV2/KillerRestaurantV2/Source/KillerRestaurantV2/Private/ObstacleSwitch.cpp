// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSwitch.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/PointLightComponent.h"

AObstacleSwitch::AObstacleSwitch()
{
	PrimaryActorTick.bCanEverTick = true;

	sceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("sceneRoot"));
	SetRootComponent(sceneRoot);

	boxInteractColl = CreateDefaultSubobject<UBoxComponent>(TEXT("boxInteractColl"));
	smComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("smComp"));
	p_light = CreateDefaultSubobject<UPointLightComponent>(TEXT("p_light"));

	boxInteractColl->SetupAttachment(sceneRoot);
	smComp->SetupAttachment(boxInteractColl);
	p_light->SetupAttachment(boxInteractColl);
}

void AObstacleSwitch::BeginPlay()
{
	Super::BeginPlay();

	boxInteractColl->OnComponentBeginOverlap.AddDynamic(this, &AFloor3ObstacleBase::OnObstacleOverlapInteract);
	DeActiveSwitch();
}

void AObstacleSwitch::ActiveSwitch()
{
	bIsActive = true;
	p_light->SetVisibility(true);

	FTimerHandle timerHdl;
	GetWorldTimerManager().SetTimer(timerHdl, [&]() {
		DeActiveSwitch();
		}, ActiveTime, false);
}

void AObstacleSwitch::DeActiveSwitch()
{
	bIsActive = false;
	p_light->SetVisibility(false);
}
