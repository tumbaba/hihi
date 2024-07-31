#include "Function.h"

void AllocateWrong(int* InPointer)
{
	// Memory 누수!
	InPointer = new int{ 10 };
}

void AllocateCorrect(int** InDoublePointer)
{
	*InDoublePointer = new int{ 10 };
}

void AllocateCorrect2(int*& InDoublePointer)
{
	InDoublePointer = new int{ 10 };
}

void Deallocate(int* InPointer)
{
	delete InPointer;
	InPointer = nullptr;
}

void Deallocate2(int** InDoublePointer)
{
	delete* InDoublePointer;
	*InDoublePointer = nullptr;
}
