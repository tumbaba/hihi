#pragma once
#include <Windows.h>
#include <string>
using namespace std;


//WindowApp* WindowApp::g_pApp = nullptr;

class WindowApp
{
public:
	WindowApp(HINSTANCE hInstance);
	~WindowApp();
	bool Initialize(int a,int b);
	int Run();
	int a, b;
	
private:
	HINSTANCE hInstance;
	HWND hwnd;
	LPCWSTR classname = L"윈도우 클래스";
	static WindowApp* g_pApp;

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
	LRESULT HandleMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

	bool RegisterWindowClass();
	bool CreateAppWindow(int nCmdShow, int a, int b);
};


//WindowApp* g_pApp = nullptr;
//extern WindowApp* g_pApp;

