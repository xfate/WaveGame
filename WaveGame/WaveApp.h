#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


class GraphicsMgr;
class InputMgr;


class WaveApp
{
public:
	WaveApp(void);
	~WaveApp(void);

	void init();
	void destory();
	void run();

	int Height() const { return m_height; }
	void Height(int val) { m_height = val; }
	int Width() const { return m_width; }
	void Width(int val) { m_width = val; }
protected:
	bool update();

	LPCWSTR m_appName;
	HINSTANCE m_instance;
	HWND m_hwnd;
	int m_width;

	int m_height;
	GraphicsMgr * m_graphicsMgr;
	InputMgr * m_inputMgr;

};

