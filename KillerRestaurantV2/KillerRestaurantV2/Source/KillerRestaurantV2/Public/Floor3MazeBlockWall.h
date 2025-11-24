// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CanInteract.h"
#include "Floor3MazeBlockWall.generated.h"

UCLASS()
class KILLERRESTAURANTV2_API AFloor3MazeBlockWall : public AActor, public ICanInteract
{
	GENERATED_BODY()
	
public:	
	AFloor3MazeBlockWall();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
	class USceneComponent* sceneRoot;

	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
	class UBoxComponent* boxColl;

	UPROPERTY(EditDefaultsOnly, Category = "MySettings")
	class UStaticMeshComponent* smComp;

	// 열기 위해 필요한 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySettings")
	FName requiredItemName; 


	// CanInteract 인터페이스 오버라이드 함수
	UFUNCTION()
	virtual void OpenWall(AKillerRestaurantCharacter* player) override;
};
