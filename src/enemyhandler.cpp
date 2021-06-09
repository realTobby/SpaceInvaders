#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemyhandler.hpp"

using namespace std;

void EnemyHandler::Init(sf::RenderWindow *prtWindow)
{
    if (!enemyTexture.loadFromFile("assets/alien1.png"))
    {
        // error...
    }
    enemyAnchorPosition = sf::Vector2f(25.f, 25.f);
    for(int i = 0; i < 10; i++)
    {
        enemyList[i].Spawn(prtWindow, &enemyTexture);
        enemyList[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + i * 70, enemyAnchorPosition.y));
    }
}

void EnemyHandler::Update()
{
    for(int i = 0; i < 10; i++)
    {
        if(isMovingRight == true)
            enemyAnchorPosition.x = enemyAnchorPosition.x + enemySpeed;
        if(enemyAnchorPosition.x > 100.f)
        {
            isMovingRight = false;
            enemyAnchorPosition.y += 8.f;
            enemyAnchorPosition.x = 99.f;
            enemySpeed = enemySpeed + 0.004f;
        }
        
        if(isMovingRight == false)
            enemyAnchorPosition.x = enemyAnchorPosition.x - enemySpeed;
        if(enemyAnchorPosition.x < 0.f)
        {
            isMovingRight = true;
            enemyAnchorPosition.y += 8.f;
            enemyAnchorPosition.x = 1.f;
            enemySpeed = enemySpeed + 0.004f;
        }
        enemyList[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + i * 70, enemyAnchorPosition.y));
        enemyList[i].DrawSprite();
    }
}