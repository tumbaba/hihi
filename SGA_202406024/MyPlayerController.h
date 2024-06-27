// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SGA_202406024_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	void Move(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);


private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_move;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_AT;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Jump;


	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> IMC_move;
	
	
};
