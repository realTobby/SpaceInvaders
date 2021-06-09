#include <SFML/Graphics.hpp>
#include <iostream>
#include "starfield.hpp"
#include "enemyhandler.hpp"
#include "player.hpp"

using namespace std;

class Game
{
    private:
        sf::Texture playerShipTexture;
        sf::RenderWindow renderWindow;
        bool isWindowInitialized = false;
        
        PlayerModel player;

        Starfield background;
        EnemyHandler enemyHandler;

    public:
        Game()
        {
            renderWindow.create(sf::VideoMode(800,600),"Space Invaders");
            //ptrWindow = &renderWindow;
            isWindowInitialized = true;


            if (!playerShipTexture.loadFromFile("assets/ship1.png"))
            {
                // error...
            }

            player.Spawn(&renderWindow, &playerShipTexture);
            background.Init(&renderWindow);
            enemyHandler.Init(&renderWindow);

        }

        void GameLoop() 
        {
            cout << "GameLoop called!" << endl;
            if(isWindowInitialized == true)
            {
                cout << "GameLoop starts..." << endl;
                while (renderWindow.isOpen())
                {
                    sf::Event event;
                    while (renderWindow.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            renderWindow.close();
                    }

                    renderWindow.clear();

                    Update();

                    renderWindow.display();
                }
            }
            cout << "GameLoop ended!" << endl;
        }

    private:

        void Update()
        {
            background.Update();
            enemyHandler.Update();
            player.Update();
        }
};








    
