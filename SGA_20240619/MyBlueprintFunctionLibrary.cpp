// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

void UMyBlueprintFunctionLibrary::OnSaveGame( FString slotname,UClass* Target)
{
    //LoadGameFromSlot(slotname,0);

    UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

    SaveGameInstance->HP = 100000;
    SaveGameInstance->Title = TEXT("Test Game Tile!#!#!#");
    SaveGameInstance->Name = TEXT("HI!##!#");

    UGameplayStatics::SaveGameToSlot(SaveGameInstance,*slotname,0);

    UE_LOG(LogTemp, Warning, TEXT("OnSaveGame: %s"),*(SaveGameInstance->Title));

    
}

void UMyBlueprintFunctionLibrary::OnLoadGame(FString slotname,UClass* Target)
{
    UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(*slotname,0));

    if(LoadGameInstance)
    {
        FString temptitle = LoadGameInstance->Title;
        FString tempName = LoadGameInstance->Name;
        int32 tempHP = LoadGameInstance->HP;

        UE_LOG(LogTemp, Warning, TEXT("OnLoadGame : %s, Name : %s  , HP : %d"),*LoadGameInstance->Title, *LoadGameInstance->Name, LoadGameInstance->HP);
    }
}

