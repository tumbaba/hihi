#pragma once
#include "stdafx.h"
class Animal
{
private:
	string name;
	int num;
	
public:
	string sound;
	Animal();    // 생성자
	Animal(string n);  // 추가 생성자
	Animal(int nu);
	Animal(int nu, string n);
	void Print();
	void Print(string n);
	void Pritn(int num);
	~Animal();   // 소멸자
	void PlaySound();


};

