#include "Animal.h"
#include "stdafx.h"

//c++은 오버로드가 있어서 1개의 클래스에 여러게의 객채를 생성할 수 있다. => 템플릿으로 한방에 해결가능
Animal::Animal()
{
	cout << "Animal::Animal() 호출" << endl;
	name = "";
	num = 0;
}

Animal::Animal(string n)
{
	name = n;
	num = 0;
	Print();
}



Animal::Animal(int nu)
{
	name = "";
	num = nu;
	Print();
}

Animal::Animal(int nu, string n)
{
	num = nu;
	name = n;
	Print();
}

void Animal::Print()
{
	cout << "name : " << name << endl;
	cout << "num : " << num<<endl;
}

void Animal::Print(string n)
{
	name = n;
	cout << "name : " << name << endl;
	cout << "num : " << num << endl;
}

void Animal::Pritn(int n)
{
	num = n;
	cout << "name : " << name << endl;
	cout << "num : " << num << endl;
}

Animal::~Animal()
{
	cout << "Animal::~Animal() 호출" << endl;
}

void Animal::PlaySound()
{
	cout << sound << endl;
}
