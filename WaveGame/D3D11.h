#ifndef _D3D11_H_
#define _D3D11_H_

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")


#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx10math.h>

class D3D11
{
public:
	D3D11(void);
	~D3D11(void);

	void init(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen, 
		float screenDepth, float screenNear);
	void shutdown();

	void beginRender();
	void endRender();

	ID3D11Device * getDevice(){return m_device;}
	ID3D11DeviceContext * getDeviceContext(){return m_deviceContext;}

	void getProjMatrix(D3DXMATRIX & mat){mat = m_projMat;}
	void getOrthoMatrix(D3DXMATRIX & mat){mat = m_orthoMat;}
	void getWorldMatrix(D3DXMATRIX & mat){mat = m_worldMat;}

	void setcolor(float r,float g,float b,float a);
//	void getDeviceInfo(D3DXMATRIX )
private:
	bool m_isWindows;
	bool m_vsyncEnabled;//´¹Ö±Í¬²½
	int m_videoCardMemory;
	char m_videoCardDescription[128];
	float m_color[4];
	IDXGISwapChain* m_swapChain;
	ID3D11Device * m_device;
	ID3D11DeviceContext * m_deviceContext;
	ID3D11RenderTargetView * m_renderView;
	ID3D11Texture2D * m_depthStencilBuffer;
	ID3D11DepthStencilState * m_depthStencilState;
	ID3D11DepthStencilView * m_depthStencilView;
	ID3D11RasterizerState * m_rasterState;

	D3DXMATRIX m_projMat;
	D3DXMATRIX m_worldMat;
	D3DXMATRIX m_orthoMat;
};
#endif