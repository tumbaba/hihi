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

