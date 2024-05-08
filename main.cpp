#include "stdafx.h"
#include "Animal.h"
#include "CDog.h"
#include "Dove.h"


int main()
{
	Animal animal;
	animal.PlaySound();
	CDog dog;
	dog.PlaySound();
	
	Dove dove;
	dove.Playsound();
	return 0;
}