#pragma once
#include "Window.h"
#include <format>
#include <string>

/**
 * Application
 */
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
		wnd.Gfx().ClearBuffer(0.5f, 1.0f, 0.6f);
		wnd.Gfx().DrawTestTriangle();
		wnd.Gfx().EndFrame();
	};
private:
	Window wnd;
};
