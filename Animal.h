#pragma once
#include "stdafx.h"
class Animal
{
private:
	string name;
	int num;
	
public:
	string sound;
	Animal();    // ������
	Animal(string n);  // �߰� ������
	Animal(int nu);
	Animal(int nu, string n);
	void Print();
	void Print(string n);
	void Pritn(int num);
	~Animal();   // �Ҹ���
	void PlaySound();


};

