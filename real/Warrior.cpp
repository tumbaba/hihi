// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"
#include "Ch6_GameModeBase.h"
#include "Components/CapsuleComponent.h"
#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	lastInput = FVector2D::ZeroVector; // 변수 초기화

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float len = lastInput.Size();

	// 플레이어의 입력이 1보다 크면 정규화한다
	if(len> 1.f)
	{
		lastInput /= len;
	}
	AddMovementInput(GetActorForwardVector(),lastInput.Y);
	AddMovementInput(GetActorRightVector(),lastInput.X);

	// 마지막 입력을 0으로 초기화 한다.
	lastInput = FVector2D(0.f,0.f);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward",this,&AWarrior::Forward);
	PlayerInputComponent->BindAxis("Back",this,&AWarrior::Back);
	PlayerInputComponent->BindAxis("Left",this,&AWarrior::Left);
	PlayerInputComponent->BindAxis("Right",this,&AWarrior::Right);

	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&AWarrior::Jump);

	FInputAxisKeyMapping backKey("Back",EKeys::S,1.f);
	FInputActionKeyMapping jump("Jump",EKeys::SpaceBar,0,0,0,0);

	// 특정 컨트롤러에 연결된 PlayerInput오브젝트
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(backKey); // 하나의 컨트롤러에만 해당함

	UPlayerInput::AddEngineDefinedActionMapping(jump);   // 정적 멤버 함수에 직접 등록하는 방법
	
	// 핫키에 대한 함수 호출
	auto GameMode = Cast<ACh6_GameModeBase>(GetWorld()->GetAuthGameMode());
	auto Func = &ACh6_GameModeBase::ButtonClicked;

	if(GameMode && Func)
	{
		PlayerInputComponent->BindAction("HotKey_UIButton_Spell",IE_Pressed, GameMode,Func);
	}

}





// void AWarrior::Forward(float amount)
// {
// 	// 앞쪽 방향으로 일정 거리만큼 플레이어를 이동시킨다.
// 	AddMovementInput(GetActorForwardVector(), amount);
// }

// void AWarrior::Back(float amount)
// {
	
// 	AddMovementInput(-GetActorForwardVector(), amount);
// }

// void AWarrior::Right(float amount)
// {
// 	// 오른쪽 방향으로 일정 거리만큼 플레이어를 이동시킨다.
// 	AddMovementInput(GetActorRightVector(), amount);
// }

// void AWarrior::Left(float amount)
// {
	
// 	AddMovementInput(-GetActorRightVector(), amount);
// }

void AWarrior::Forward(float amount)
{
	//추가된 양을 += 연산으로 lastInput.Y에 추가했다
	//::Back()과 같은 함수가 값을 수정했을 수도 있으므로
	// 마지막 값에 추가한 모습을 볼 수 있다.
	lastInput.Y += amount;
}

void AWarrior::Back(float amount)
{
	
	lastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{

	lastInput.X += amount;
}

void AWarrior::Left(float amount)
{
	
	lastInput.X -= amount;
}

void AWarrior::OnOverlapsBegin_Implementation(UPrimitiveComponent* Comp,
						 					AActor* OtherActor, 
						 					UPrimitiveComponent* OtherComp,
						 					int32 OtherBodyIndex, 
						 					bool bFromSweep, 
						 					const FHitResult&SweepRsult)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior began"),*OtherActor->GetName());
	
}

void AWarrior::OnOverlapsEnd_Implementation(UPrimitiveComponent* Comp,
						 					AActor* OtherActor, 
						 					UPrimitiveComponent* OtherComp,
						 					int32 OtherBodyIndex)
{
	
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior end"),*OtherActor->GetName());
	
}


void AWarrior::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if(RootComponent)
	{
		// 경계를 갖는 모든 컴포넌트에 접촉 가능을 추가한다.
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AWarrior::OnOverlapsBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AWarrior::OnOverlapsEnd);
	}
}