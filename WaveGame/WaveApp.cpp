#include "WaveApp.h"
#include "GraphicsMgr.h"
#include "InputMgr.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch(umessage)
	{
		// Check if the window is being destroyed.
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		// Check if the window is being closed.
	case WM_CLOSE:
		{
			PostQuitMessage(0);		
			return 0;
		}

		// All other messages pass to the message handler in the system class.
	default:
		{
			return DefWindowProc(hwnd, umessage, wparam, lparam);
		}
	}
}
WaveApp::WaveApp(void)
{
	m_width = 1024;
	m_height = 768;
	m_appName = L"WaveGame by xfate";

}


WaveApp::~WaveApp(void)
{
}

void WaveApp::init()
{
	WNDCLASSEX wc;
	
	m_instance = GetModuleHandle(NULL);
	wc.style = CS_HREDRAW|CS_VREDRAW|CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = m_instance;
	wc.hIcon		 = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm       = wc.hIcon;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = m_appName;
	wc.cbSize        = sizeof(WNDCLASSEX);
	int posX = (GetSystemMetrics(SM_CXSCREEN) - m_width)  / 2;
	int posY = (GetSystemMetrics(SM_CYSCREEN) - m_height) / 2;
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_appName, m_appName, 
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		posX, posY, m_width, m_height, NULL, NULL, m_instance, NULL);
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);
	ShowCursor(false);

	m_graphicsMgr = new GraphicsMgr();
	m_inputMgr = new InputMgr();

	m_inputMgr->init();

	m_graphicsMgr->Height(m_height);
	m_graphicsMgr->Width(m_width);
	m_graphicsMgr->init(m_hwnd);

}

void WaveApp::destory()
{
	if(m_graphicsMgr)
		m_graphicsMgr->destory();
	if(m_inputMgr)
		m_inputMgr->destory();
	delete m_inputMgr; m_inputMgr = NULL;
	delete m_graphicsMgr; m_graphicsMgr = NULL;
}

void WaveApp::run()
{
	MSG msg;
	while(1)
	{
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if(msg.message != WM_QUIT)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
				break;
		}
		else if(!update())
		{
			while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			break;
		}
	}
}

bool WaveApp::update()
{
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	WaveApp* app;
	app = new WaveApp;
	app->init();
	app->run();
	app->destory();
	delete app;
	app = 0;

	return 0;
}