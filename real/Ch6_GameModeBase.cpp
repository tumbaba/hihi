// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/UserWidget.h"
#include "Ch6_GameModeBase.h"


void ACh6_GameModeBase::BeginPlay()
{
    Super::BeginPlay();
    if(widget)
    {
        UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(),widget);

        if(Menu)
        {
            Menu->AddToViewport();
            GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
        }
    }
}
