#include <Windows.h>   // 윈도우 API함수 사용하기위해 주ㅇ가
#include "../winAppDll/math.h"
#include <iostream>

//typedef int (*math_func)(int, int);

using namespace std;
typedef int (*math_func)(int, int);
int main()
{

	// 1. 라이브러리 열기 (dll파일을 읽어오기)
	HINSTANCE hinstLib = LoadLibrary(L"WinAppDll.dll");
	if (!hinstLib)
	{
		std::cout << "WinAppDll.dll" << endl;
		return 1;
	}
	math_func add = (math_func)GetProcAddress(hinstLib, "Add");

	if (!add)
	{
		cout << L"Add함수를 찾지 못했습니다." << endl;
		return 1;
	}

	cout <<  Add(10, 20) << endl;



	FreeLibrary(hinstLib);   //메모리 해제

	return 0;
}