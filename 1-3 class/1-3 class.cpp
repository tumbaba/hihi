﻿// 01-03.Class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Class/Class.h"

int main()
{
	int aa = 0;
	static int a = 10;
	int bb = a;
	{
		{
			// FClass라는 설계도(청사진)를 기반으로
			// 실체화된 사례(instance)를 만든다
			// An Object is an instance of a class
			FClass ClassInstance;
			FClass ClassInstance2 = FClass();
			FClass ClassInstance3 = FClass(ClassInstance2);
		}

		{
			FClass ClassInstance;
			FClass ClassInstance2;
			FClass ClassInstance3;

			ClassInstance2.operator=(ClassInstance3);
			ClassInstance2 = ClassInstance3;
			ClassInstance = (ClassInstance2 = ClassInstance3);
			ClassInstance.operator=(ClassInstance2.operator=(ClassInstance3));
		}

		{
			FClass2 ClassInstance;
			FClass2 ClassInstance2 = FClass2(ClassInstance);
			/*ClassInstance.a = 9999;
			*ClassInstance.Pointer = 12453421;*/
			ClassInstance2 = ClassInstance;
		}
		{
			FClass2* ClassInstance = new FClass2;
			FClass2* ClassInstance2 = new FClass2(*ClassInstance);

			// 이건 주소만 바뀜!
			// ClassInstance2 = ClassInstance;

			// operator= 호출!
			*ClassInstance2 = *ClassInstance;

			delete ClassInstance;
			delete ClassInstance2;
		}
		{
			int a = FClass2::StaticVar1;
			//FClass2::Hello();
			FClass2 ClassInstance;
			ClassInstance.Hello();
			FClass2::Hello2();
			ClassInstance.Hello2();
		}
		{
			FClass2* Class = nullptr;

			// Hello 함수 내부에서 this에 접근하고 있어서 nullptr 가 this에 들어가는 경우
			// Crash가 발생한다.
			// 하지만, HelloTest 함수는 내부에서 this에 접근하고 있지 않기 때문에 문제가 없다.
			Class->HelloTest();
			Class->Hello();
		}
	}
}
