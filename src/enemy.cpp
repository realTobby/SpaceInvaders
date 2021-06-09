#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemy.hpp"

using namespace std;

// Konstruktor
EnemyModel::EnemyModel()
{
	SetPosition(sf::Vector2f(0.f,0.f));
	cout << "Enemy erstellt!" << endl;
	isMovingRight = true;
}

// Übergebe den Pointer zum RenderWindow
void EnemyModel::Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture)
{
	Init(ptrWindow, ptrTexture);
}
