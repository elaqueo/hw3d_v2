#include "Window.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	try {
		Window wnd(800, 600, TEXT("\xD83C\xDF7A Direct3D Window"));

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1) {
			return -1;
		}

		return (int)msg.wParam;
	}
	catch (const Exception& e) {
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONERROR);
	}
	catch (std::exception& e) {
		MessageBoxA(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONERROR);
	}
	catch (...) {
		MessageBoxA(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONERROR);
	}

	return -1;
}