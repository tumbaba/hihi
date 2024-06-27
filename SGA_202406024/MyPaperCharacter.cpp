// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "EnhancedInputComponent.h"



#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"


#include "UObject/ConstructorHelpers.h"




AMyPaperCharacter::AMyPaperCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    //인풋관련 초기 세팅
    // Input Actions
    static ConstructorHelpers::FObjectFinder<UInputAction> IA_Move_OBJ(TEXT("/Game/IA_move"));
    IA_Move = IA_Move_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> IA_Attack_OBJ(TEXT("/Game/IA_AT"));
    IA_Attack = IA_Attack_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UInputAction> IA_Jump_OBJ(TEXT("/Game/IA_jump"));
    IA_Jump = IA_Jump_OBJ.Object;

    // static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_move_OBJ(TEXT("/Game/IMC_move"));
    // IMC_move = IMC_move_OBJ.Object;

  

    //애니메이션 초기 세팅
    // Flipbook Animations
    static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_Idle_OBJ(TEXT("/Game/2D/generic_char_v0_2/png/red/move/red_idel"));
    FB_Char_Idle = FB_Idle_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_Run_OBJ(TEXT("/Game/2D/generic_char_v0_2/png/red/move/red_run"));
    FB_Char_Run = FB_Run_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_Attack01_OBJ(TEXT("/Game/2D/generic_char_v0_2/png/red/move/red_Attack"));
    FB_Char_Attack01 = FB_Attack01_OBJ.Object;

    static ConstructorHelpers::FObjectFinder<UPaperFlipbook> FB_Jump_OBJ(TEXT("/Game/2D/generic_char_v0_2/png/red/move/red_jump"));
    FB_Char_Jump = FB_Jump_OBJ.Object;

    //카메라, 스프링암 컴퍼넌트를 값 세팅
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 200.0f;
    SpringArm->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f)); //횡스크롤 화면 
    //SpringArm->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;

    // Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
    

    bIsAttacking = false;
}



void AMyPaperCharacter::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Your 333e"));

    bIsAttacking = false;
    if( GetSprite() != nullptr)
    {
        GetSprite()->SetFlipbook(FB_Char_Idle);
    
     //GetSprite 이벤트 함수 등록
        GetSprite()->OnFinishedPlaying.AddDynamic(this, &AMyPaperCharacter::OnAttackFinished);
         UE_LOG(LogTemp, Warning, TEXT("Your not null"));
    }

    
    
}
    


void AMyPaperCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //추가 구현하면 됨.
    UpdateAnimation();
   

}



void AMyPaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    UE_LOG(LogTemp, Warning, TEXT("Setting up player input component"));

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (IA_Move)
        {
            EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMyPaperCharacter::Move);
            UE_LOG(LogTemp, Warning, TEXT("Bound IA_Move action"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("IA_Move is not valid"));
        }

        if (IA_Attack)
        {
            EnhancedInputComponent->BindAction(IA_Attack, ETriggerEvent::Triggered, this, &AMyPaperCharacter::Attack);
            UE_LOG(LogTemp, Warning, TEXT("Bound IA_Attack action"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("IA_Attack is not valid"));
        }

        if (IA_Jump)
        {
            EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AMyPaperCharacter::Jump);
            UE_LOG(LogTemp, Warning, TEXT("Bound IA_Jump action"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("IA_Jump is not valid"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerInputComponent is not a UEnhancedInputComponent"));
    }
}


void AMyPaperCharacter::Move(const FInputActionValue& Value)
{
    if (!bIsAttacking)
    {
        FVector2D MovementVector = Value.Get<FVector2D>();
    AddMovementInput(FVector(MovementVector.X, 0.0f, 0.0f));

    UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent"));
    }
    
}

void AMyPaperCharacter::Attack(const FInputActionValue& Value)
{
    // 공격 로직을 여기에 구현
    if (!bIsAttacking)
    {
        bIsAttacking = true;
        GetSprite()->SetFlipbook(FB_Char_Attack01);
        GetSprite()->SetLooping(false);        
        GetSprite()->PlayFromStart();

        // GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
        // {
        //     bIsAttacking = false;
        // });

        UE_LOG(LogTemp, Warning, TEXT("Attack!"));
    }
}


void AMyPaperCharacter::Jump(const FInputActionValue& Value)
{
    if(!bIsAttacking)
    {
        bIsAttacking = true;
        GetSprite()->SetFlipbook(FB_Char_Jump);
        GetSprite()->SetLooping(false);        
        GetSprite()->PlayFromStart();

        bPressedJump = true;
        JumpKeyHoldTime = 0.0f;
    }
}


void AMyPaperCharacter::OnAttackFinished()
{
    UE_LOG(LogTemp, Warning, TEXT("OnAttackFinished!"));

    bIsAttacking = false;
    GetSprite()->SetLooping(true);
    GetSprite()->Play();
    UpdateAnimation();

   /* GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
    {bIsAttacking
        bIsAttacking = false;
    });*/
}


void AMyPaperCharacter::OnJumpFinished()
{
    UE_LOG(LogTemp, Warning, TEXT("OnJumpFinished!"));

    bIsAttacking = false;
    GetSprite()->SetLooping(true);
    GetSprite()->Play();
    UpdateAnimation();

   /* GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
    {
        bIsAttacking = false;
    });*/
}

void AMyPaperCharacter::UpdateAnimation()
{

    const FVector PlayerVelocity = GetVelocity();
    float TravelDirection = PlayerVelocity.X;
    if (!bIsAttacking)
    {        
        //if (MovementInput.SizeSquared() > 0.0f)
        if(TravelDirection < 0.0f)
        {
            GetSprite()->SetFlipbook(FB_Char_Run);
        }
        else if(TravelDirection > 0.0f)
        {
            GetSprite()->SetFlipbook(FB_Char_Run);
        }
        else if(TravelDirection == 0.0f)
        {
            GetSprite()->SetFlipbook(FB_Char_Idle);
        }
    }
    
    

    if(Controller != nullptr)
    {
        if(TravelDirection < 0.0f)
        {
            Controller->SetControlRotation(FRotator(0.0f,180.0f,0.0f));
        }
        else if(TravelDirection > 0.0f)
        {
            Controller->SetControlRotation(FRotator(0.0f,0.0f,0.0f));
        }
    }

}


