#include "stdafx.h"
#include "Animal.h"
#include "CDog.h"
#include "Dove.h"


int main()
{
	Animal* panimal;// = new Animal;   // ���ο� ��ü

	Animal anumal;
	Animal hi("sadfsdf");
	Animal num(18484);

	CDog dog3;

	dog3.Print("���ο� �۸���");
	dog3.PlaySound();

	Dove dove;
	dove.Print("���� ��ѱ�");
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