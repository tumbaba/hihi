#include "Dove.h"

Dove::Dove()
{
	 sound = "��������";
}

Dove::~Dove()
{
}

void Dove::Playsound()
{
	Animal::PlaySound();
	Print("Dove::PlaySound() �Լ�ȣ��");
}
