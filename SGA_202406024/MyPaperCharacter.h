// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"


#include "EnhancedInputComponent.h"

#include "InputAction.h"
#include "InputMappingContext.h"


#include "PaperFlipbook.h"
#include "InputActionValue.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyPaperCharacter.generated.h" 






/**
 * 
 */
UCLASS()
class SGA_202406024_API AMyPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMyPaperCharacter();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	//이동 Input 이벤트
	void Move(const FInputActionValue& Value);

	//공격 Input 이벤트
	void Attack(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);

	UFUNCTION() void OnJumpFinished();

	UFUNCTION() void OnAttackFinished();

	void UpdateAnimation();

private:

	// Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Move;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_Jump;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Input",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> IMC_move;

	// Flipbook Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Run;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Attack01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Jump;


	// Movement state
	bool bIsAttacking;
	FVector2D MovementInput;

	// 카메라와 Spring Arm Components 를  추가함.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> Camera;

	
};
