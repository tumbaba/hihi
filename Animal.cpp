#include "Animal.h"
#include "stdafx.h"

//c++�� �����ε尡 �־ 1���� Ŭ������ �������� ��ä�� ������ �� �ִ�. => ���ø����� �ѹ濡 �ذᰡ��
Animal::Animal()
{
	cout << "Animal::Animal() ȣ��" << endl;
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
	cout << "Animal::~Animal() ȣ��" << endl;
}

void Animal::PlaySound()
{
	cout << sound << endl;
}
