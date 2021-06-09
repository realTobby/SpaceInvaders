#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "starfield.hpp"
#include "enemyhandler.hpp"


using namespace std;

class Game
{
    private:
        sf::RenderWindow renderWindow;
        sf::RenderWindow *ptrWindow;
        bool isWindowInitialized = false;
        
        
    
        sf::Vector2f playerPosition = sf::Vector2f(400.f,500.f);
        bool canShoot = true;
        sf::Vector2f shotPosition = sf::Vector2f(playerPosition.x, playerPosition.y);

        Starfield background;
        EnemyHandler enemyHandler;

    public:
        Game()
        {
            srand (time(NULL));
            
            renderWindow.create(sf::VideoMode(800,600),"Space Invaders");
            ptrWindow = &renderWindow;
            isWindowInitialized = true;

            background.Init(ptrWindow);
            enemyHandler.Init(ptrWindow);

        }

        void GameLoop() 
        {
            cout << "GameLoop called!" << endl;
            cout << "GameLoop starts..." << endl;

            if(isWindowInitialized == true)
            {
                while (ptrWindow -> isOpen())
                {
                    sf::Event event;
                    while (ptrWindow -> pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            ptrWindow -> close();
                    }

                    ptrWindow -> clear();

                    Update();

                    ptrWindow -> display();
                }
            }
            
            cout << "GameLoop ended!" << endl;
        }

    private:

        void Update()
        {
            background.Update();
            enemyHandler.Update();
        }

        void shoot()
        {
            shotPosition.x = playerPosition.x + 16.f;
            shotPosition.y = playerPosition.y;
            canShoot = false;
        }

        void moveShoot()
        {
            if(canShoot == false)
            {
                shotPosition.y = shotPosition.y - 0.25f;
                sf::RectangleShape shotShape(sf::Vector2f(10.f,20.f));
                shotShape.setFillColor(sf::Color::Red);
                shotShape.setPosition(shotPosition);
                ptrWindow -> draw(shotShape);

                if(shotPosition.y < 0)
                    canShoot = true;
            }
        }

        void PlayerMove()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerPosition.x > 0)
            {
                // move left...
                //cout << "Move Left..." << endl;
                playerPosition.x = playerPosition.x - 0.09f;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerPosition.x < 800-48)
            {
                // move right...
                //cout << "Move Right..." << endl;
                playerPosition.x = playerPosition.x + 0.09f;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot == true)
            {
                shoot();
            }
        }

        void DrawPlayer()
        {
            sf::RectangleShape playerShape(sf::Vector2f(48.f,48.f));
            playerShape.setFillColor(sf::Color::Green);
            playerShape.setPosition(playerPosition);
            ptrWindow -> draw(playerShape);
        }
};








    
