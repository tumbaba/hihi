// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyFristActor.h"




void AMyGameModeBase::BeginPlay()
{
    // 이 함수의 부모 클래스 버전을 호출
    Super::BeginPlay();

    // 10초간 화면에 빨간색 메시지 출력
    GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("Actor Spawing"));

    // AMyFirstActor 클래스의 인스턴스를 기본위치로 소환
    FTransform SpawnLocation;
    SpawnedActor = GetWorld()->SpawnActor<AMyFristActor>(AMyFristActor::StaticClass(),SpawnLocation);
    

    FTimerHandle Timer;
    GetWorldTimerManager().SetTimer(Timer, this, &AMyGameModeBase::DestroyActorFunction, 10);
    
}

void AMyGameModeBase::DestroyActorFunction()
{
    if(SpawnedActor != nullptr)
    {
        // 빨간 메시지를 10초동안 표시한다.
        UE_LOG(LogTemp, Warning, TEXT("121"));
        GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("Actor Destroyed"));
        UE_LOG(LogTemp, Warning, TEXT("1213131"));

        SpawnedActor->Destroy();
    }
}
