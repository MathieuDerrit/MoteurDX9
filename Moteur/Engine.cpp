#include "Engine.h"
bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	keyboard.EnableAutoRepeatChars();
	return this->render_window.Initialize(this, hInstance, window_title, window_class, width, height);
}

bool Engine::ProcessMessages()
{
	return this->render_window.ProcessMessages();
}

void Engine::Update()
{
	while (!keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = keyboard.ReadChar();		
		std::string outmsg = "Char: ";
		outmsg += ch;
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str());
	}

	while (!keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
	}

	while (!mouse.EventBufferIsEmpty())
	{		
		//Voir les coordonn�es de la souris dans la fen�tre
		MouseEvent me = mouse.ReadEvent();
		std::string outmsg = "X: ";
		outmsg += std::to_string(me.GetPosX());
		outmsg += ", Y: ";
		outmsg += std::to_string(me.GetPosY());
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str());
	}
}