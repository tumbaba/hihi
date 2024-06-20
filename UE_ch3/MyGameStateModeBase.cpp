// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateModeBase.h"


AMyGameStateModeBase::AMyGameStateModeBase()
{
    CurrentScore = 0;
}

void AMyGameStateModeBase::SetScore(int32 NewScore)
{
    
   CurrentScore = NewScore;
}


int32 AMyGameStateModeBase::GetScore()
{
    
     return CurrentScore;
}