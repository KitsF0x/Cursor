#include <iostream>
#include <Windows.h>
#include <sstream>
#include <gdiplus.h>
#include <Gdiplusheaders.h>
#include <memory>

#pragma comment(lib, "gdiplus.lib")

POINT getCursorPosition()
{
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	return cursorPos;
}

std::shared_ptr<Gdiplus::Image> getImage(const std::string& filename)
{
	std::wstring wfilename = std::wstring(filename.begin(), filename.end());
	Gdiplus::Image* imagePtr = new Gdiplus::Image(wfilename.c_str());
	std::shared_ptr<Gdiplus::Image> imageSmartPtr(imagePtr);
	return imageSmartPtr;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &input, nullptr);

	HDC hdc = GetDC(nullptr);
	Gdiplus::Graphics graphics(hdc);

	const auto bitmap = getImage("./image.bmp");

	while (true)
	{
		POINT p = getCursorPosition();
		graphics.DrawImage(bitmap.get(), static_cast<INT>(p.x), static_cast<INT>(p.y));
	}
	ReleaseDC(nullptr, hdc);
	Gdiplus::GdiplusShutdown(token);
}