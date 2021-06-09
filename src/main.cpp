#define _WIN32_WINNT 0x0500

#ifdef _WIN32
    #include <windows.h>
#endif

#include <SFML/Graphics.hpp>
#include "game.cpp"

int main()
{

// Wenn es sich um ein Windows-System handelt soll die Konsole verschwinden
#ifdef _WIN32
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_HIDE );
#endif

    // Einsteig in das eigentliche Spiel
    Game gameobj; // Spiel wird grundsätzlich erstellt (RenderWindow, startup Variablen, usw...)
    gameobj.GameLoop(); // Spiel Schleife
    return 0;
}
