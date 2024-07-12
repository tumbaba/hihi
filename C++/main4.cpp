#include <iostream>
#include "CArr.h"

class CTest
{
private:
	int a;

public:
	CTest()
	{
		a = 0;
	}
};


int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}





int main()
{
	// 구조체 --> 클래스
	
	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음 , 은닉성
	// 멤버 함수들
	
	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// 구조체 버전 가변배열 --> 클래스 버전


	// c++ 동적할당 new , delete

	CTest* pTest = new CTest;
	delete pTest;



	CArr carr;
	carr.PushBack(10);
	carr.PushBack(20);
	carr.PushBack(30);

	int  iData = carr[1];
	carr[1] = 100;


	// 함수 템플릿
	int i = Add<int>(10, 20);

	return 0;
}