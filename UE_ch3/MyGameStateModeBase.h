// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameStateModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE_CH3_API AMyGameStateModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// CurrentScore 초기화를 위한 생성자
	AMyGameStateModeBase();

	// CurrnetScore 변수를 설정
	UFUNCTION()
	void SetScore(int32 newScore);

	//Getter
	UFUNCTION()
	int32 GetScore();

private:
	UPROPERTY()
	int32 CurrentScore;
	
};
