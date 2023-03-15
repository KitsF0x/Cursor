#include <iostream>
#include <Windows.h>
#include <sstream>
#include <gdiplus.h>
#include <Gdiplusheaders.h>
#include <memory>


POINT getCursorPosition()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return cursorPos;
}

std::shared_ptr<Gdiplus::Bitmap> getBitmap(const std::string& filename)
{
	std::wstring wfilename = std::wstring(filename.begin(), filename.end());
	Gdiplus::Bitmap* bitmapPtr = new Gdiplus::Bitmap(wfilename.c_str());
	std::shared_ptr<Gdiplus::Bitmap> bitmapSmartptr(bitmapPtr);
	return bitmapSmartptr;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
}