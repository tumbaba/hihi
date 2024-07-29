#include "Function.h"
#include <iostream>

void FunctionName(int a, int b)
{
	std::cout << a << b << std::endl;
}

int AddFunction(const int InA, const int InB)
{
	const int Result = InA + InB;
	return Result;
}

double AddFunction(const double InA, const double InB)
{
	const double Result = InA + InB;
	return Result;
}

unsigned long long Factorial(unsigned char InF)
{
	if (InF == 0)
	{
		return 1;
	}

	return InF * Factorial(InF - 1);
}

void HasFlags(unsigned char InProperty)
{
	std::cout << "HasFlags\n";
	// 0000 0101
	// 0000 0001
	// ---------- AND
	// 0000 0001
	if (InProperty & EPropertyFlags::EProperty1)
	{
		std::cout << "EPropertyFlags::EProperty1\n";
	}
	if (InProperty & EPropertyFlags::EProperty2)
	{
		std::cout << "EPropertyFlags::EProperty2\n";
	}
	if (InProperty & EPropertyFlags::EProperty3)
	{
		std::cout << "EPropertyFlags::EProperty3\n";
	}
	if (InProperty & EPropertyFlags::EProperty4)
	{
		std::cout << "EPropertyFlags::EProperty4\n";
	}
	if (InProperty & EPropertyFlags::EProperty5)
	{
		std::cout << "EPropertyFlags::EProperty5\n";
	}
	if (InProperty & EPropertyFlags::EProperty6)
	{
		std::cout << "EPropertyFlags::EProperty6\n";
	}
	if (InProperty & EPropertyFlags::EProperty7)
	{
		std::cout << "EPropertyFlags::EProperty7\n";
	}

	std::cout << "HasFlags end\n";
}

int CallByValue(int InValue)
{
	InValue = 10;
	return InValue;
}

FParam CallByValue(FParam InParam)
{
	InParam.Value[0] = 9999;
	InParam.Value[5] = 5555;
	return InParam;
}

void CallByPointer(int* InPointer)
{
	*InPointer = 1234;
}

void CallByReference(int& InReference)
{
	InReference = 1234;
}

void CallByPointer(FParam* InPointer)
{
	InPointer->Value[0] = 9999;
	InPointer->Value[5] = 5555;

	(*InPointer).Value[2] = 2222;
}

void CallByReference(FParam& InReference)
{
	InReference.Value[0] = 9999;
	InReference.Value[5] = 5555;

	InReference.Value[2] = 2222;
}

FParam::FParam()
{
	std::cout << "FParam\n";
}

FParam::~FParam()
{
	std::cout << "~FParam\n";
}

