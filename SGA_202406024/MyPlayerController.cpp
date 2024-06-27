// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyPlayerController::AMyPlayerController()
{
    static ConstructorHelpers::FObjectFinder<UInputAction> IA_move_OBJ(TEXT("/Game/IA_move"));
    IA_move = IA_move_OBJ.Object;
    static ConstructorHelpers::FObjectFinder<UInputAction> IA_AT_OBJ(TEXT("/Game/IA_AT"));
    IA_AT = IA_AT_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> IA_Jump_OBJ(TEXT("/Game/IA_jump"));
    IA_Jump = IA_Jump_OBJ.Object;

    //static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_move_OBJ(TEXT("/Game/IMC_move"));
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_move_OBJ(TEXT("/Game/IMC_move"));
    IMC_move = IMC_move_OBJ.Object;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(IMC_move.Get(),0);
    }

}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(IA_move.Get(),ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
        EnhancedInputComponent->BindAction(IA_AT.Get(),ETriggerEvent::Triggered, this, &AMyPlayerController::Attack);
    }
}


void AMyPlayerController::Move(const FInputActionValue& Value)
{
    // if(APawn* Controllerdpawn = GetPawn())

    // {
    //      FVector2D MovementPawn = GetPawn();

    //     //x ControllerdPawn->AddMovementInput(FVector(addMovementInput.x,0,0.f,0,0.f));
    // }
   if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter* MyCharacter = Cast<AMyPaperCharacter>(ControlledPawn))
        {
            MyCharacter->Move(Value);
        }
    }


}

void AMyPlayerController::Attack(const FInputActionValue& Value)
{
    if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter* MyCharacter = Cast<AMyPaperCharacter>(ControlledPawn))
        {
            MyCharacter->Attack(Value);
        }
    }


}

void AMyPlayerController::Jump(const FInputActionValue& Value)
{
    if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter* MyCharacter = Cast<AMyPaperCharacter>(ControlledPawn))
        {
            MyCharacter->Jump(Value);
        }
    }


}