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
	
	
	//virtual void PlaySound() = 0; //순수가상함수(자식이 반드시 있어야함)// 자식클래스에서 오버라이드 가능
	virtual void PlaySound();
protected:  // 자식 클래스 한테만 노출, 외부에는 허용불가
	
public:
	~Animal();   // 소멸자
};

