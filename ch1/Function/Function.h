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
