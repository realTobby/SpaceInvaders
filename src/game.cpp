#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "starfield.hpp"
#include "enemyhandler.hpp"
#include "player.hpp"

using namespace std;

class Game
{
    private:
        sf::RenderWindow renderWindow;
        sf::RenderWindow *ptrWindow;
        bool isWindowInitialized = false;
        
        PlayerModel player;

        Starfield background;
        EnemyHandler enemyHandler;

    public:
        Game()
        {
            srand (time(NULL));
            
            renderWindow.create(sf::VideoMode(800,600),"Space Invaders");
            ptrWindow = &renderWindow;
            isWindowInitialized = true;

            player.Init(ptrWindow);
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
            player.Update();
        }

        //void shoot()
        //{
        //    shotPosition.x = playerPosition.x + 16.f;
        //    shotPosition.y = playerPosition.y;
        //    canShoot = false;
        //}
        // TODO ===> BOTH FUNCTIONS INTO PLAYER.CPP
        //void moveShoot()
        //{
        //    if(canShoot == false)
        //    {
        //        shotPosition.y = shotPosition.y - 0.25f;
        //        sf::RectangleShape shotShape(sf::Vector2f(10.f,20.f));
        //        shotShape.setFillColor(sf::Color::Red);
        //        shotShape.setPosition(shotPosition);
        //        ptrWindow -> draw(shotShape);

        //        if(shotPosition.y < 0)
        //            canShoot = true;
        //    }
        //}

};








    
