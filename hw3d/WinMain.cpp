#include "App.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	try {
		return App{}.Run();
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