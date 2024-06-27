// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "UObject/ConstructorHelpers.h"


AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyPaperCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
