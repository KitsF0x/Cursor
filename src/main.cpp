#include <iostream>
#include <Windows.h>
#include <sstream>


POINT getCursorPosition()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return cursorPos;
}

int main()
{
	POINT cursorPos;
	while (true)
	{
		cursorPos = getCursorPosition();
		std::cout << "X: " << cursorPos.x << "Y: " << cursorPos.y << std::endl;
	}
}