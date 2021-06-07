#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



using namespace std;

class Game
{
    private:
        sf::RenderWindow mainWindow;
        bool isWindowInitialized = false;
        sf::Vector2f starLayer1[100];
        sf::Vector2f starLayer2[100];
        sf::Vector2f starLayer3[100];

        void Starfield()
        {
            // create basic star shape
            sf::RectangleShape shape(sf::Vector2f(2.f,2.f));
            shape.setFillColor(sf::Color::White);

            for(int i = 0; i < 100; i++)
            {
                shape.setPosition(starLayer1[i]);
                starLayer1[i].x = starLayer1[i].x - 0.09f;

                if(starLayer1[i].x <= 0)
                    starLayer1[i].x = 800;
                mainWindow.draw(shape);

                shape.setPosition(starLayer2[i]);
                starLayer2[i].x = starLayer2[i].x - 0.06f;

                if(starLayer2[i].x <= 0)
                    starLayer2[i].x = 800;
                mainWindow.draw(shape);

                shape.setPosition(starLayer3[i]);
                starLayer3[i].x = starLayer3[i].x - 0.02f;

                if(starLayer3[i].x <= 0)
                    starLayer3[i].x = 800;
                mainWindow.draw(shape);
            }

        }


    public:
        Game()
        {
            srand (time(NULL));

            mainWindow.create(sf::VideoMode(800,600),"Space Invaders");
            isWindowInitialized = true;

            for(int i = 0; i < 100; i++)
            {
                starLayer1[i].x = rand() % 800 + 1;
                starLayer1[i].y = rand() % 600 + 1;

                starLayer2[i].x = rand() % 800 + 1;
                starLayer2[i].y = rand() % 600 + 1;

                starLayer3[i].x = rand() % 800 + 1;
                starLayer3[i].y = rand() % 600 + 1;
            }

        }

        void GameLoop() 
        {
            cout << "GameLoop called!" << endl;
            cout << "GameLoop starts..." << endl;

            if(isWindowInitialized == true)
            {
                while (mainWindow.isOpen())
                {
                    sf::Event event;
                    while (mainWindow.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            mainWindow.close();
                    }

                    mainWindow.clear();

                    Starfield();

                    mainWindow.display();
                }
            }
            
            cout << "GameLoop ended!" << endl;
        }

};








    
