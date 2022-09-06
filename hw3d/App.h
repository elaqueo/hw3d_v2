#pragma once
#include "Window.h"
#include "Timer.h"
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
		wnd.Gfx().ClearBuffer(0.35f, 0.8f, 0.5f);
		wnd.Gfx().DrawTestTriangle(
			timer.Peek(),
			0.0f,
			0.0f
		);
		wnd.Gfx().DrawTestTriangle(
			timer.Peek(),
			wnd.mouse.GetPosX() / 400.0f - 1.0f,
			-wnd.mouse.GetPosY() / 300.0f + 1.0f
		);
		wnd.Gfx().EndFrame();
	};
private:
	Window wnd;
	Timer timer;
};
