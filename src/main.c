#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wce;
	HWND hWnd;
	MSG msg;

	ZeroMemory(&wce, sizeof(wce));
	wce.cbSize = sizeof(wce);
	wce.lpfnWndProc = WndProc;
	wce.hInstance = hInst;
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wce.hCursor = LoadCursor(NULL, IDC_ARROW);
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wce.lpszClassName = "WindowClass";
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wce))
	{
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "Title", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
						  CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInst, NULL);

	if (!hWnd)
	{
		return 0;
	}

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;

		hdc = BeginPaint(hWnd, &ps);

		// draw here

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_SIZE:
	{
		int width, height;
		width = LOWORD(lParam);
		height = HIWORD(lParam);

		break;
	}
	case WM_MOUSEMOVE:
	{
		int x, y;
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x, y;
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		break;
	}
	case WM_KEYDOWN:
	{
		int key;
		key = wParam;

		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
