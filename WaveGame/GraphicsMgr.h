#pragma once
#include "define.h"
class GraphicsMgr
{
public:
	void init(HWND hwnd);
	void destory();
	GraphicsMgr(void);
	~GraphicsMgr(void);
	int Width() const { return m_width; }
	void Width(int val) { m_width = val; }
	int Height() const { return m_height; }
	void Height(int val) { m_height = val; }
protected:
	int m_height;
	HWND m_hwnd;
	int m_width;

};

