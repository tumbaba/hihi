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
