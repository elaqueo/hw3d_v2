#pragma once
#include "Win32.h"
#include <d3d11.h>

class Graphics
{
public:
	Graphics(HWND hWnd);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void EndFrame();
	void ClearBuffer(float red, float green, float blue) noexcept;
private:
	ID3D11Device* pDevice{};
	ID3D11DeviceContext* pContext{};
	IDXGISwapChain* pSwap{};
	ID3D11RenderTargetView* pTarget{};
};

