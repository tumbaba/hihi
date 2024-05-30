#include <Windows.h>   // ������ API�Լ� ����ϱ����� �֤���
#include "../winAppDll/math.h"
#include <iostream>

//typedef int (*math_func)(int, int);

using namespace std;
typedef int (*math_func)(int, int);
int main()
{

	// 1. ���̺귯�� ���� (dll������ �о����)
	HINSTANCE hinstLib = LoadLibrary(L"WinAppDll.dll");
	if (!hinstLib)
	{
		std::cout << "WinAppDll.dll" << endl;
		return 1;
	}
	math_func add = (math_func)GetProcAddress(hinstLib, "Add");

	if (!add)
	{
		cout << L"Add�Լ��� ã�� ���߽��ϴ�." << endl;
		return 1;
	}

	cout <<  Add(10, 20) << endl;



	FreeLibrary(hinstLib);   //�޸� ����

	return 0;
}