
#include <SFML/Graphics.hpp>
#include <iostream>
#include "hidingspot.hpp"

using namespace std;

void HidingSot::Init(sf::RenderWindow *prtWindow)
{
    if (!enemyTexture.loadFromFile("data/sprites/alien1.png"))
    {
        // error...
    }
}

