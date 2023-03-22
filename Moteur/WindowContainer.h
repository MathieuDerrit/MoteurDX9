#pragma once
#include "moteur.h"

class WindowContainer
{
public:
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	//RenderWindow render_window; 
	KeyboardClass keyboard;
	MouseClass mouse;
private:

};
