#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "enemy.hpp"


using namespace std;

class Game
{
    private:
        sf::RenderWindow renderWindow;
        sf::RenderWindow *ptrWindow;
        bool isWindowInitialized = false;
        sf::Vector2f starLayer1[100];
        sf::Vector2f starLayer2[100];
        sf::Vector2f starLayer3[100];
        EnemyModel enemies[10];
        sf::Vector2f enemyAnchorPosition;
        sf::Vector2f playerPosition = sf::Vector2f(400.f,500.f);
        bool canShoot = true;
        sf::Vector2f shotPosition = sf::Vector2f(playerPosition.x, playerPosition.y);
        bool enemiesMoveRight = true;
        float enemySpeed = 0.007f;
        sf::Texture enemyTexture;
        sf::Texture *ptrEnemyTexture;

    public:
        Game()
        {
            srand (time(NULL));
            
            renderWindow.create(sf::VideoMode(800,600),"Space Invaders");
            ptrWindow = &renderWindow;
            isWindowInitialized = true;

            enemyAnchorPosition = sf::Vector2f(25.f, 25.f);

            for(int i = 0; i < 100; i++)
            {
                starLayer1[i].x = rand() % 800 + 1;
                starLayer1[i].y = rand() % 600 + 1;

                starLayer2[i].x = rand() % 800 + 1;
                starLayer2[i].y = rand() % 600 + 1;

                starLayer3[i].x = rand() % 800 + 1;
                starLayer3[i].y = rand() % 600 + 1;
            }

            SpawnEnemies();

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

                    Starfield();
                    DrawPlayer();
                    DrawEnemies();
                    PlayerMove();

                    moveShoot();

                    ptrWindow -> display();
                }
            }
            
            cout << "GameLoop ended!" << endl;
        }

    private:
        void Starfield()
        {
            // create basic star shape
            sf::RectangleShape shape(sf::Vector2f(1.2f,1.2f));
            shape.setFillColor(sf::Color::White);

            for(int i = 0; i < 100; i++)
            {
                shape.setPosition(starLayer1[i]);
                starLayer1[i].y = starLayer1[i].y - 0.09f;

                if(starLayer1[i].y <= 0)
                {
                    starLayer1[i].x = rand() % 800 + 1;
                    starLayer1[i].y = 600;
                }
                ptrWindow -> draw(shape);

                shape.setPosition(starLayer2[i]);
                starLayer2[i].y = starLayer2[i].y - 0.06f;

                if(starLayer2[i].y <= 0)
                {
                    starLayer2[i].x = rand() % 800 + 1;
                    starLayer2[i].y = 600;
                }
                ptrWindow -> draw(shape);

                shape.setPosition(starLayer3[i]);
                starLayer3[i].y = starLayer3[i].y - 0.02f;

                if(starLayer3[i].y <= 0)
                {
                    starLayer3[i].x = rand() % 800 + 1;
                    starLayer3[i].y = 600;
                }
                ptrWindow -> draw(shape);
            }

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

        void SpawnEnemies()
        {
            if (!enemyTexture.loadFromFile("assets/alien1.png"))
            {
                // error...
            }
            ptrEnemyTexture = &enemyTexture;

            for(int i = 0; i < 10; i++)
            {
                enemies[i].Spawn(ptrWindow, ptrEnemyTexture);
                enemies[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + i * 70, enemyAnchorPosition.y));
            }
        }

        void DrawEnemies()
        {
            for(int i = 0; i < 10; i++)
            {
                enemies[i].Draw();
				
				if(enemiesMoveRight == true)
					enemyAnchorPosition.x = enemyAnchorPosition.x + enemySpeed;
				if(enemyAnchorPosition.x > 350.f)
				{
					enemiesMoveRight = false;
					enemyAnchorPosition.y += 16.f;
					enemyAnchorPosition.x = 349.f;
					enemySpeed = enemySpeed + 0.004f;
				}
				
				if(enemiesMoveRight == false)
					enemyAnchorPosition.x = enemyAnchorPosition.x - enemySpeed;
				if(enemyAnchorPosition.x < 0.f)
				{
					enemiesMoveRight = true;
					enemyAnchorPosition.y += 16.f;
					enemyAnchorPosition.x = 1.f;
					enemySpeed = enemySpeed + 0.004f;
				}
                enemies[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + i * 70, enemyAnchorPosition.y));
            }
        }
};








    
