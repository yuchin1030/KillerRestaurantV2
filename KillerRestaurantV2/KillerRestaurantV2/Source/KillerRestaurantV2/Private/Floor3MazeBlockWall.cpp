// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor3MazeBlockWall.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "CanInteract.h"
#include "KillerRestaurantCharacter.h"

AFloor3MazeBlockWall::AFloor3MazeBlockWall()
{
	PrimaryActorTick.bCanEverTick = true;

	sceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("sceneRoot"));
	boxColl = CreateDefaultSubobject<UBoxComponent>(TEXT("boxColl"));
	smComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("smComp"));

	SetRootComponent(sceneRoot);
	boxColl->SetupAttachment(sceneRoot);
	smComp->SetupAttachment(boxColl);

	boxColl->SetBoxExtent(FVector(250, 55, 32));
	smComp->SetRelativeScale3D(FVector(10, 10, 5));
}

void AFloor3MazeBlockWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFloor3MazeBlockWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloor3MazeBlockWall::OpenWall(AKillerRestaurantCharacter* player)
{
	if (player->HasItem(requiredItemName))
	{
		UE_LOG(LogTemp, Warning, TEXT("Can Open"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You don't have item"));

	}
}

