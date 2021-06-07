#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Game
{
    private:
        sf::RenderWindow mainWindow;
        bool isWindowInitialized = false;

    public:
        Game()
        {
            mainWindow.create(sf::VideoMode(800,600),"Main Window");
            isWindowInitialized = true;
        }

        void GameLoop() 
        {
            cout << "GameLoop called!" << endl;
            cout << "GameLoop starts..." << endl;

            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);

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
                    mainWindow.draw(shape);
                    mainWindow.display();
                }
            }
            
            cout << "GameLoop ended!" << endl;
        }

    

};








    
