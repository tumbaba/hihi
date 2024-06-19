// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SGA_20240619_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "MySave")
	static void OnSaveGame(FString slotname,UClass* Target);

	UFUNCTION(BlueprintCallable, Category = "MySave")
	static void OnLoadGame(FString slotname,UClass* Target);
};
