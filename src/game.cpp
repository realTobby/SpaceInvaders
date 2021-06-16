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
        Logging myLogger;
        sf::Texture playerShipTexture; // Textur für das Spieler-Objekt
        sf::Texture uiBaseTexture;
        sf::RenderWindow renderWindow; // EINZIGES RenderWindow (Screen) auf dem alles gezeichnet wird (Draw), => wird als PointerReferenz übergeben
        bool isWindowInitialized;
        sf::Font uiFont;
        sf::Sprite uiBase;
        
        PlayerModel player; // Eigenständiges Spieler-objekt

        Starfield background; // Eigenständiges Hintergrund-objekt
        EnemyHandler enemyHandler; // Logik und zusammenhalt der Gegner-Objekte

        int playerScore;
        sf::Text playerScoreText;

        sf::Texture hut1_texture;
        sf::Sprite hutLeft_sprite;
        sf::Sprite hutRight_sprite;


        void LoadTextures()
        {
            if (!playerShipTexture.loadFromFile("data/sprites/ship1.png")) // Lädt die Textur ein
            {
                // error...
            }

            if (!uiBaseTexture.loadFromFile("data/sprites/uiBase.png")) // Lädt die Textur ein
            {
                // error...
            }

            if (!hut1_texture.loadFromFile("data/sprites/hut1.png")) // Lädt die Textur ein
            {
                // error...
            }

            hutLeft_sprite.setTexture(hut1_texture);
            hutRight_sprite.setTexture(hut1_texture);
            hutRight_sprite.setTextureRect(sf::IntRect(24, 0, -24, 39));

        }

        void LoadFonts()
        {

            if (!uiFont.loadFromFile("data/fonts/pixelfont.ttf"))
            {
                // error...
            }

            // select the font
            playerScoreText.setFont(uiFont); // font is a sf::Font

            // set the string to display
            playerScoreText.setString("Score: " + to_string(playerScore));

            // set the character size
            playerScoreText.setCharacterSize(24); // in pixels, not points!

            // set the color
            playerScoreText.setFillColor(sf::Color::White);

            playerScoreText.setPosition(sf::Vector2f(48, 4));

            // set the text style
            playerScoreText.setStyle(sf::Text::Bold);


        }


    public:
        Game() : myLogger("log.txt")
        {
            playerScore = 0;

            renderWindow.create(sf::VideoMode(800,600),"Space Invaders"); // RenderWindow wird erstellt und bleibt durch PointerReferenz auch das einzige
            //ptrWindow = &renderWindow;
            isWindowInitialized = true;

            LoadTextures();
            LoadFonts();
            uiBase.setTexture(uiBaseTexture);
            uiBase.setPosition(0,0);

            player.Spawn(&renderWindow, &playerShipTexture); // Initalisiert das Spieler-Objekt mit den PointerReferenzen
            background.Init(&renderWindow); // Initialisiert das Hintergrund-Objekt mit dem WindowPointer
            enemyHandler.Init(&renderWindow, &background); // Initialisiert die GegnerLogik mit WindowPointer

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
            CheckForCollisions();
            renderWindow.draw(uiBase);
            renderWindow.draw(playerScoreText);
            


            
            // TODO: create own HutClass, and a HidingSpotHandler, transfer drawing code to that and implement dithering when shot
            hutLeft_sprite.setPosition(sf::Vector2f(100,400));
            hutRight_sprite.setPosition(sf::Vector2f(124,400)); 
            renderWindow.draw(hutLeft_sprite);
            renderWindow.draw(hutRight_sprite);

            hutLeft_sprite.setPosition(sf::Vector2f(200,400));
            hutRight_sprite.setPosition(sf::Vector2f(224,400)); 
            renderWindow.draw(hutLeft_sprite);
            renderWindow.draw(hutRight_sprite);

            hutLeft_sprite.setPosition(sf::Vector2f(300,400));
            hutRight_sprite.setPosition(sf::Vector2f(324,400)); 
            renderWindow.draw(hutLeft_sprite);
            renderWindow.draw(hutRight_sprite);

            hutLeft_sprite.setPosition(sf::Vector2f(400,400));
            hutRight_sprite.setPosition(sf::Vector2f(424,400)); 
            renderWindow.draw(hutLeft_sprite);
            renderWindow.draw(hutRight_sprite);
        }

        void CheckForCollisions()
        {
            // get all positions from enemies
            // get position from the shot
            // check if the shot position is in reach of enemy
            int isHitScoreMultipier = enemyHandler.CheckForCollision(player.GetShotPosition());
            if(isHitScoreMultipier != -1)
            {
                player.canShoot = true;
                playerScore = playerScore + isHitScoreMultipier;
                playerScoreText.setString("Score: " + to_string(playerScore));
            }
        }
};








    
