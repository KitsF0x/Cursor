#include <Windows.h>
#include <string>
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
	if (imagePtr->GetLastStatus() != Gdiplus::Ok)
	{
		MessageBox(NULL, "Cannot load image", "", MB_OK | MB_ICONHAND);
	}
	std::shared_ptr<Gdiplus::Image> imageSmartPtr(imagePtr);
	return imageSmartPtr;
}

void renderImageAtCursorPosition(Gdiplus::Graphics& graphics, Gdiplus::Image* image)
{
	while (true)
	{
		POINT p = getCursorPosition();
		graphics.DrawImage(image, static_cast<INT>(p.x), static_cast<INT>(p.y));
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_ESCAPE))
		{
			exit(0);
		}
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &input, nullptr);

	HDC hdc = GetDC(nullptr);
	Gdiplus::Graphics graphics(hdc);

	const auto image = getImage("./image.bmp");

	while (true)
	{
		renderImageAtCursorPosition(graphics, image.get());
	}

	ReleaseDC(nullptr, hdc);
	Gdiplus::GdiplusShutdown(token);
}