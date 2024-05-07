#include "stdafx.h"
#include "Animal.h"
#include "CDog.h"
#include "Dove.h"


int main()
{
	Animal* panimal;// = new Animal;   // 货肺款 按眉

	Animal anumal;
	Animal hi("sadfsdf");
	Animal num(18484);

	CDog dog3;

	dog3.Print("货肺款 港港捞");
	dog3.PlaySound();

	Dove dove;
	dove.Print("岗柳 厚笛扁");
	dove.PlaySound();
	
	panimal = &dog3;
	panimal->PlaySound();

	panimal = &dove;
	panimal->PlaySound();
	
	Animal& refanimal = dog3;
	refanimal.PlaySound();
	refanimal = dove;
	dove.PlaySound();

	

	return 0;
}