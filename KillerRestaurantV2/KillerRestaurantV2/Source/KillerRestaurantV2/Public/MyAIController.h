// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class KILLERRESTAURANTV2_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    AMyAIController();

protected:
    virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySettings")
    class UAIPerceptionComponent* PerceptionComp;

    UPROPERTY()
    class UAISenseConfig_Sight* SightConfig;

    UPROPERTY()
    class UAISenseConfig_Hearing* HearingConfig;

    UFUNCTION()
    void OnTargetPerceived(AActor* Actor, FAIStimulus Stimulus);

    UPROPERTY(EditDefaultsOnly, Category = "MySettings")
    class UBehaviorTree* BehaviorTreeAsset;
};
