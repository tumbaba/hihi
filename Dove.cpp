#include "Dove.h"

Dove::Dove()
{
	 sound = "구구구구";
}

Dove::~Dove()
{
}

void Dove::Playsound()
{
	Animal::PlaySound();
	Print("Dove::PlaySound() 함수호출");
}
