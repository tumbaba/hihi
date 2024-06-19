// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SGA_20240619_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = MyGame)
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = MyGame)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = MyGame)
	int32 HP;
	
};
