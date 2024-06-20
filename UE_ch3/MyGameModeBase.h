// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include <iterator>
#include "MyFristActor.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_CH3_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	AMyFristActor* SpawnedActor;

	UFUNCTION()
	void DestroyActorFunction();
	
};
