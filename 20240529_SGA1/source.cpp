#include "WindowApp.h"



int WINAPI wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{


    WindowApp app(hInstance);
    if (!app.Initialize(400,400)) {
        return 1;
    }
    return app.Run();
}

//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
//
//
//
//int WINAPI wWinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevInstance,
//				   LPWSTR IpcmdLine,
//				   int nCmdShow)
//{
//
//	
//
//	const wchar_t CLASS_NAME[] = L"Simple Windows";
//	 // 1. ������ Ŭ���� ���
//	WNDCLASS wc = {};
//
//	wc.lpfnWndProc = WindowProc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = L"Simple Windows";
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
//	RegisterClass(&wc);
//	 
//	 // 2. ������ ����
//	HWND hwnd = CreateWindowEx(0,
//		CLASS_NAME,   // ������ Ŭ���� ����
//		L"���� ������ ���α׷�",  // ������ Ŭ���� Ÿ��Ʋ
//		WS_OVERLAPPEDWINDOW,
//		0, 0,     //CW_USEDEFAULT, CW_USEDEFAULT,  // ������ ���� ��ġ
//		640, 480,     //CW_USEDEFAULT, CW_USEDEFAULT,  //  ������ width, height
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//	);
//
//	if (hwnd == NULL)
//	{
//		return 0;
//	}
//
//	ShowWindow(hwnd, nCmdShow);
//
//	 // 3. �޽��� ���� ó��
//	MSG msg = {};
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);  //  Ű���� �Է¸޼��� ��ȯ
//		DispatchMessage(&msg);   //  ������ ���ν����� ����
//	}
//
//
//
//	return 0;
//}
//
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
//{
//
//	PAINTSTRUCT ps;
//	HDC hdc;
//
//	switch (uMsg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//
//	case WM_SIZE:
//		InvalidateRect(hwnd, NULL, TRUE);
//		return 0;
//
//	case WM_PAINT: {
//		hdc = BeginPaint(hwnd, &ps);
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));
//
//		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));//5 : �� �β� 
//		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255)); //���� ä��� �κ�
//		HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);  //
//		// ���׸���
//		Ellipse(hdc, 50, 50, 200, 200);
//
//
//		HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 255, 0));
//		HBRUSH hOldBrush2 = (HBRUSH)SelectObject(hdc, hBrush2);
//		Ellipse(hdc, 220, 50, 370, 200);
//		SelectObject(hdc, hOldBrush2);
//		DeleteObject(hBrush2);
//
//		// �� 3: �Ķ���
//		HBRUSH hBrush3 = CreateSolidBrush(RGB(0, 0, 255));
//		HBRUSH hOldBrush3 = (HBRUSH)SelectObject(hdc, hBrush3);
//		Ellipse(hdc, 390, 50, 540, 200);
//		SelectObject(hdc, hOldBrush3);
//		DeleteObject(hBrush3);
//
//
//		Arc(hdc ,250, 250, 400, 400, 300, 300, 350, 350);
//
//		MoveToEx(hdc, 100, 50, NULL);
//		LineTo(hdc, 100, 100);
//		LineTo(hdc, 200, 200);
//
//
//		SetTextColor(hdc, RGB(255, 0, 0));
//		SetTextAlign(hdc, TA_CENTER);
//		int num = 30;
//		wstring strc = L"add(10,20) = " + to_wstring(num);
//		TextOut(hdc, 100, 100, strc.c_str(), (int)strc.size());
//		SetTextColor(hdc, RGB(0, 0, 255));
//		TextOut(hdc, 100, 130, strc.c_str(), (int)strc.size());
//
//
//
//		EndPaint(hwnd, &ps);
//		return 0;
//	}
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, IParam);
//	}
//}
