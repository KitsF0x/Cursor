#include <iostream>
#include <Windows.h>
#include <sstream>


POINT getCursorPosition()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return cursorPos;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

}