#include "stdafx.h"

int main()
{
	//casting
	 
	//c��Ÿ��
	int num = 10;
	float fnum;

	fnum = (float)num; // Ÿ���ɽ���

	
	cout << fnum << endl;
	printf("%f\n", fnum);

	double b = (double)num;
	cout << b << endl;
	printf("%.9f\n", b);
	
	fnum = 3.141592f;
	num = (int)fnum;

	cout << num << endl;


	// static_cast<Ÿ��>  
	//�����ɽ���

	double  dnum = 777.1415;

	int d = static_cast<int>(dnum);

	cout << d << endl;

	//�����ɽ��� (������ ���)

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


	//4. const_cast ��� �ɽ���

	const float i = 3.14;

	float* num = const_cast<float*>(&i);
	num = 5.000;
	cout <<"i:"<<i<<endl;


	return 0;

}