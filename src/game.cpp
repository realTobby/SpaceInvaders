#include <SFML/Graphics.hpp>
#include <iostream>
#include "starfield.hpp"
#include "enemyhandler.hpp"
#include "player.hpp"
#include "logging.hpp"

using namespace std;

class Game
{
    private:
        Logging myLogger = Logging("log.txt");
        sf::Texture playerShipTexture; // Textur für das Spieler-Objekt
        sf::RenderWindow renderWindow; // EINZIGES RenderWindow (Screen) auf dem alles gezeichnet wird (Draw), => wird als PointerReferenz übergeben
        bool isWindowInitialized = false;
        
        PlayerModel player; // Eigenständiges Spieler-objekt

        Starfield background; // Eigenständiges Hintergrund-objekt
        EnemyHandler enemyHandler; // Logik und zusammenhalt der Gegner-Objekte

    public:
        Game()
        {
            renderWindow.create(sf::VideoMode(800,600),"Space Invaders"); // RenderWindow wird erstellt und bleibt durch PointerReferenz auch das einzige
            //ptrWindow = &renderWindow;
            isWindowInitialized = true;

            if (!playerShipTexture.loadFromFile("assets/ship1.png")) // Lädt die Textur ein
            {
                // error...
            }

            player.Spawn(&renderWindow, &playerShipTexture); // Initalisiert das Spieler-Objekt mit den PointerReferenzen
            background.Init(&renderWindow); // Initialisiert das Hintergrund-Objekt mit dem WindowPointer
            enemyHandler.Init(&renderWindow); // Initialisiert die GegnerLogik mit WindowPointer

        }

        // Spiel Schleife
        void GameLoop() 
        {
            myLogger.Log(Logging::Information, "Game Loop called");
            if(isWindowInitialized == true)
            {
                myLogger.Log(Logging::Information, "Game Loop started");
                while (renderWindow.isOpen()) // Solange Fenster offen ist (in dieser game.cpp wird mit dem renderWindow und nicht dem Pointer gearbeitet)
                {
                    sf::Event event;
                    while (renderWindow.pollEvent(event)) // hole alle Events die gefeuert werden
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            myLogger.Log(Logging::Information, "Window Closed");
                            renderWindow.close();
                        }
                        
                    }

                    renderWindow.clear(); // Bereinige den Screen

                    Update(); // Führe eine Update-Sequenz durch

                    renderWindow.display(); // Zeige den neugezeichneten Bildschirm an
                }
            }
            myLogger.Log(Logging::Information, "Game Loop ended");
        }

    private:

        // Spiel Logik wird hier eingebracht, die einzelnen Objekte und Handler haben ihre eigene Logik, diese wird hier ausgeführt
        void Update()
        {
            background.Update();
            enemyHandler.Update();
            player.Update();
        }
};








    
