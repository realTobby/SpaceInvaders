#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.hpp"

using namespace std;

// Übergebe den Pointer zum RenderWindow
void DrawableModel::Init(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture)
{
	windowPointer = ptrWindow;
	sprite.setTexture((*ptrTexture));
}


void DrawableModel::DrawSprite()
{
	sprite.setPosition(GetPosition());
	windowPointer -> draw(sprite);
}

void DrawableModel::DrawShape(sf::RectangleShape shapeToDraw)
{
	windowPointer -> draw(shapeToDraw);
}

// Hole Position
sf::Vector2f DrawableModel::GetPosition()
{
	return Position;
}

// Setze Position
void DrawableModel::SetPosition(sf::Vector2f pos)
{
	Position = pos;
}