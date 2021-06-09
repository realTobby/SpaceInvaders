#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Starfield.hpp"


using namespace std;

// Übergebe den Pointer zum RenderWindow
void Starfield::Init(sf::RenderWindow *ptrWindow)
{
    starSpeed1 = 0.09f;
    starSpeed2 = 0.06f;
    starSpeed3 = 0.02f;

	windowPointer = ptrWindow;
	starShape = sf::RectangleShape(sf::Vector2f(1.2f,1.2f));
	starShape.setFillColor(sf::Color::White);
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

void Starfield::SpeedUp()
{
    starSpeed1 += 0.05f;
    starSpeed2 += 0.05f;
    starSpeed3 += 0.05f;
}

// Zeichne das Enemy
void Starfield::Draw()
{      
	windowPointer -> draw(starShape);
}

void Starfield::Update()
{
    for(int i = 0; i < 100; i++)
    {
        starShape.setPosition(starLayer1[i]);
        starLayer1[i].y = starLayer1[i].y + starSpeed1;

        if(starLayer1[i].y >= 600)
        {
            starLayer1[i].x = rand() % 800 + 1;
            starLayer1[i].y = 0;
        }
        Starfield::Draw();

        starShape.setPosition(starLayer2[i]);
        starLayer2[i].y = starLayer2[i].y + starSpeed2;

        if(starLayer2[i].y >= 600)
        {
            starLayer2[i].x = rand() % 800 + 1;
            starLayer2[i].y = 0;
        }
        Starfield::Draw();

        starShape.setPosition(starLayer3[i]);
        starLayer3[i].y = starLayer3[i].y + starSpeed3;

        if(starLayer3[i].y >= 600)
        {
            starLayer3[i].x = rand() % 800 + 1;
            starLayer3[i].y = 0;
        }
        Starfield::Draw();
    }
}

