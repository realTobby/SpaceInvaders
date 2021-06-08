#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "game.cpp"

int main()
{
	HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_HIDE );

	Game gameobj;
    gameobj.GameLoop();
    return 0;
}