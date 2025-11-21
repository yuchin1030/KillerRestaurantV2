// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor3ItemBase.generated.h"

UCLASS()
class KILLERRESTAURANTV2_API AFloor3ItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AFloor3ItemBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
