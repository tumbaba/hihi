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
