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
	// ����ü --> Ŭ����
	
	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ���� , ���м�
	// ��� �Լ���
	
	// 2. ���

	// 3. ������

	// 4. �߻�ȭ

	// ����ü ���� �����迭 --> Ŭ���� ����


	// c++ �����Ҵ� new , delete

	CTest* pTest = new CTest;
	delete pTest;



	CArr carr;
	carr.PushBack(10);
	carr.PushBack(20);
	carr.PushBack(30);

	int  iData = carr[1];
	carr[1] = 100;


	// �Լ� ���ø�
	int i = Add<int>(10, 20);

	return 0;
}