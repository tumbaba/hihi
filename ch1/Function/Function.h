#pragma once
void __cdecl FunctionName(int a, int b);

int AddFunction(const int InA, const int InB);
// �����ε� (overloading)
// InA: double ���� �־��ּ���
// InB: double ���� �־��ּ���
// return: InA �� InB�� ��
double AddFunction(const double InA, const double InB);

// ����Լ�: �� �Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ�
[[nodiscard("Hello")]] unsigned long long Factorial(unsigned char InF);

// Bit flags
// �Ӽ� ���� ���� ǥ�Ⱑ �ʿ��� �� ���
// Ex) ���尡 �ִ°�, Ŭ��ŷ�� �����Ѱ�, �������� �����Ѱ�
enum EPropertyFlags : unsigned char // 1Byte
{
	// 16����		2����			���� ����Ʈ ����	10����
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
