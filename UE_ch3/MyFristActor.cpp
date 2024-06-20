// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFristActor.h"

// Sets default values
AMyFristActor::AMyFristActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// 이 오브젝트를 StaticMeshComponent를 생성하고 Mesh에 할당한다.
	Mesh  = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");

	//auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	//MsehAsset을 설정하기 전에 유효한지 검사한다.
	if(MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMyFristActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFristActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

