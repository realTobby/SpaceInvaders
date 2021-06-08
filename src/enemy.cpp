#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemy.hpp"

using namespace std;

EnemyModel::EnemyModel()
{
	SetPosition(sf::Vector2f(0.f,0.f));
	cout << "Enemy erstellt!" << endl;
}

void EnemyModel::Spawn(sf::RenderWindow *ptrWindow)
{
	windowPointer = ptrWindow;
	sf::RectangleShape enemyShape = sf::RectangleShape(sf::Vector2f(32.f,32.f));
	enemyShape.setFillColor(sf::Color::Red);
    
}

void EnemyModel::Draw()
{
	enemyShape.setPosition(Position);        
	windowPointer -> draw(enemyShape);
}

sf::Vector2f EnemyModel::GetPosition()
{
	return Position;
}

void EnemyModel::SetPosition(sf::Vector2f pos)
{
	Position = pos;
}