#include "stdafx.h"

int main()
{
	//casting
	 
	//c스타일
	int num = 10;
	float fnum;

	fnum = (float)num; // 타입케스팅

	
	cout << fnum << endl;
	printf("%f\n", fnum);

	double b = (double)num;
	cout << b << endl;
	printf("%.9f\n", b);
	
	fnum = 3.141592f;
	num = (int)fnum;

	cout << num << endl;


	// static_cast<타입>  
	//정적케스팅

	double  dnum = 777.1415;

	int d = static_cast<int>(dnum);

	cout << d << endl;

	//동적케스팅 (포인터 사용)

	class Animal
	{public:
		float a = 132.145f;
		void foo() {}
	};
	class Dog : public Animal
	{

	};

	Animal* parentPtr = new Animal();


	Dog* dog = (Dog*)parentPtr;
	Animal* dog = dynamic_cast<Animal*>(parentPtr);


	//4. const_cast 상수 케스팅

	const float i = 3.14;

	float* num = const_cast<float*>(&i);
	num = 5.000;
	cout <<"i:"<<i<<endl;


	return 0;

}