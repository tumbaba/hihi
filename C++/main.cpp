#include "Arr.h"
#include <iostream>
#include <time.h>


using namespace std;


void Sortbubble(int Count, int* ArrData)
{

	while (true)
	{
		bool hi = true;

		for (int i = 0; i < Count - 1; i++)
		{


			if (ArrData[i] > ArrData[i + 1])
			{
				int temp = ArrData[i];
				ArrData[i] = ArrData[i + 1];
				ArrData[i + 1] = temp;
				hi = false;
			}


		}
		if (hi)
		{
			break;
		}

	}

}

void Test()
{

}

int main()
{

	void(*pFunc)(void) = nullptr;

	pFunc = Test;


	Arr s = {};
	Init(&s);

	for (int i = 0; i < 10; i++)
	{
		int irand = rand() % 10;
		PushBack(&s, irand);
	}
	Sort(&s,&Sortbubble );

	for (int i = 0; i < 10; i++)
	{
		cout << s.pArr[i] << endl;
	}

	return 0;
}