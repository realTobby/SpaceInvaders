#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemyhandler.hpp"

using namespace std;

void EnemyHandler::Init(sf::RenderWindow *prtWindow, Starfield *starsRef)
{
    ptrStarfield = starsRef;
    enemySpeed = 0.007f;
    isMovingRight = true;
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
        if(enemyList[i].isAlive == true)
        {
            if(isMovingRight == true)
            enemyAnchorPosition.x = enemyAnchorPosition.x + enemySpeed;
        if(enemyAnchorPosition.x > 100.f)
        {
            isMovingRight = false;
            enemyAnchorPosition.y += 8.f;
            enemyAnchorPosition.x = 99.f;
            enemySpeed = enemySpeed + 0.004f;
            ptrStarfield -> SpeedUp();
        }
        
        if(isMovingRight == false)
            enemyAnchorPosition.x = enemyAnchorPosition.x - enemySpeed;
        if(enemyAnchorPosition.x < 0.f)
        {
            isMovingRight = true;
            enemyAnchorPosition.y += 8.f;
            enemyAnchorPosition.x = 1.f;
            enemySpeed = enemySpeed + 0.004f;
            ptrStarfield -> SpeedUp();
        }
        enemyList[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + i * 70, enemyAnchorPosition.y));
        enemyList[i].DrawSprite();
        }

        
    }
}

void EnemyHandler::CheckForCollision(sf::Vector2f shotPos)
{
    for(int i = 0; i < 10; i++)
    {
        if(enemyList[i].isAlive == true)
        {
            sf::Vector2f e = enemyList[i].GetPosition();
            if(shotPos.x >= e.x && shotPos.x <= e.x + 64)
            {
                if(shotPos.y <= e.y + 64 && shotPos.y >= e.y)
                {
                    enemyList[i].Die();
                }
            }    
        }
        
    }
}
