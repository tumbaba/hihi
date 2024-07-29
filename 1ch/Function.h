#pragma once
void __cdecl FunctionName(int a, int b);

int AddFunction(const int InA, const int InB);
// 오버로딩 (overloading)
// InA: double 값을 넣어주세요
// InB: double 값을 넣어주세요
// return: InA 와 InB의 합
double AddFunction(const double InA, const double InB);

// 재귀함수: 그 함수가 자기 자신을 호출하는 함수
[[nodiscard("Hello")]] unsigned long long Factorial(unsigned char InF);

// Bit flags
// 속성 정보 유무 표기가 필요할 때 사용
// Ex) 쉴드가 있는가, 클로킹이 가능한가, 스팀팩이 가능한가
enum EPropertyFlags : unsigned char // 1Byte
{
	// 16진수		2진수			왼쪽 쉬프트 연산	10진수
	ENone = 0x00,			// 0000 0000	0						0
	EProperty1 = 0x01,			// 0000 0001	1 << 0					1
	EProperty2 = 0x02,			// 0000 0010	1 << 1					2
	EProperty3 = 0x04,			// 0000 0100	1 << 2					4
	EProperty4 = 0x08,			// 0000 1000	1 << 3					8
	EProperty5 = 0x10,			// 0001 0000	1 << 4				   16
	EProperty6 = 0x20,			// 0010 0000	1 << 5				   32
	EProperty7 = 0x40,			// 0100 0000	1 << 6				   64
	EProperty8 = 0x80,			// 1000 0000	1 << 7				  128
};

void HasFlags(unsigned char InProperty);

int CallByValue(int InValue);

#include <iostream>
struct FParam
{
	// 생성자
	FParam();

	// 복사 생성자: 선언하지 않으면 자동으로 만들어 줍니다.
	// (기본 복사 생성자의 경우)InOther에 있는 데이터를 
	// 신규로 만들어질 인스턴스의 맴버 변수에 복제한다
	FParam(const FParam& InOther)
		: A(InOther.A)
	{
		std::cout << "FParam copy constructor\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InOther.Value[i];
		}
	}

	void operator=(const FParam& InOther)
	{
		std::cout << "FParam operator=\n";
		for (int i = 0; i < 1000; ++i)
		{
			this->Value[i] = InOther.Value[i];
		}

		A = InOther.A;
	}

	// 소멸자
	~FParam();
	int Value[1000]{};
	int A = 999;
};

FParam CallByValue(FParam InParam);

void CallByPointer(int* InPointer);
void CallByReference(int& InReference);
void CallByPointer(FParam* InPointer);
void CallByReference(FParam& InReference);

inline void TestConstructor(FParam* InThis)
{
	int a = InThis->A;
}

struct FTTest
{
	FTTest()
	{
		int* ThisAddress = (int*)this;
		int* aAddres = &this->a;
	}

	int a = 200;
	int b = 400;
};

inline void TestConstructor(FTTest* InPointer)
{
	int aa = InPointer->a;
	int bb = InPointer->b;
	int AA = *((int*)InPointer + 0);
	int BB = *((int*)InPointer + 1);
}
inline void TestConstructor(void* InPointer)
{
	int AA = *((int*)InPointer + 0);
	int BB = *((int*)InPointer + 1);
}
