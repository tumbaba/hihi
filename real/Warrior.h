// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Warrior.generated.h"

UCLASS()
class REAL_API AWarrior : public ACharacter
{
	GENERATED_BODY()

public:
	// 이 캐릭터 속성의 기본값 설정
	AWarrior();

protected:
	// 게임이 시작되거나 생성될 때 호출됨
	virtual void BeginPlay() override;

	FVector2D lastInput;

public:	
	// 이전 프레임의 이동
	virtual void Tick(float DeltaTime) override;

	// 입력 기능 연동을 위해 호출됨
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Forward(float amount);
	void Back(float amount);
	void Left(float amount);
	void Right(float amount);
	
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
	void OnOverlapsBegin(UPrimitiveComponent* Comp,
						 AActor* OtherActor, 
						 UPrimitiveComponent* OtherComp,
						 int32 OtherBodyIndex, 
						 bool bFromSweep, 
						 const FHitResult&SweepRsult);
	
	
	
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
	void OnOverlapsEnd(UPrimitiveComponent* Comp,
						 AActor* OtherActor, 
						 UPrimitiveComponent* OtherComp,
						 int32 OtherBodyIndex);
	

	virtual void PostInitializeComponents() override;

};
