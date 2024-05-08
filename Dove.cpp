#include "Dove.h"

Dove::Dove()
{
	 sound = "备备备备";
}

Dove::~Dove()
{
}

void Dove::Playsound()
{
	Animal::PlaySound();
	Print("Dove::PlaySound() 窃荐龋免");
}
