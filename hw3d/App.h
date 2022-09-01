#pragma once
#include "Window.h"
#include <format>
#include <string>

class App
{
public:
	App() : wnd(800, 600, TEXT("Direct3D")) {}
	int Run() {
		while (true) {
			if (const auto ecode = Window::ProcessMessages()) {
				return *ecode;
			}
			DoFrame();
		}
	}
private:
	void DoFrame() {
	};
private:
	Window wnd;
};

