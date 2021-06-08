#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemy.hpp"

using namespace std;

// Konstruktor
EnemyModel::EnemyModel()
{
	SetPosition(sf::Vector2f(0.f,0.f));
	cout << "Enemy erstellt!" << endl;
}

// Übergebe den Pointer zum RenderWindow
void EnemyModel::Spawn(sf::RenderWindow *ptrWindow)
{
	windowPointer = ptrWindow;
	enemyShape = sf::RectangleShape(sf::Vector2f(32.f,32.f));
	enemyShape.setFillColor(sf::Color::Red);
    
}

// Zeichne das Enemy
void EnemyModel::Draw()
{
	enemyShape.setPosition(Position);        
	windowPointer -> draw(enemyShape);
}

// Hole Position
sf::Vector2f EnemyModel::GetPosition()
{
	return Position;
}

// Setze Position
void EnemyModel::SetPosition(sf::Vector2f pos)
{
	Position = pos;
}