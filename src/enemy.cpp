#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemy.hpp"

using namespace std;

EnemyModel::EnemyModel()
{
	SetPosition(sf::Vector2f(0.f,0.f));
	cout << "Enemy erstellt!" << endl;
}

sf::Vector2f EnemyModel::GetPosition()
{
	return Position;
}

void EnemyModel::SetPosition(sf::Vector2f pos)
{
	Position = pos;
}