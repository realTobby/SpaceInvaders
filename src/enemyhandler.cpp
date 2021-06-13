#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemyhandler.hpp"

using namespace std;

void EnemyHandler::Init(sf::RenderWindow *prtWindow, Starfield *starsRef)
{
    enemyCount = 20;
    enemyRows = 2;
    enemyList = std::vector<EnemyModel>(enemyCount);
    ptrStarfield = starsRef;
    enemySpeed = 0.004f;
    isMovingRight = true;
    if (!enemyTexture.loadFromFile("data/sprites/alien1.png"))
    {
        // error...
    }
    enemyAnchorPosition = sf::Vector2f(25.f, 25.f);
    int i = 0;
    for(int y = 0; y < enemyRows; y++)
    {
        for(int x = 0; x < enemyCount / enemyRows; x++)
        {
            enemyList[i].Spawn(prtWindow, &enemyTexture);
            enemyList[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + x * 70, enemyAnchorPosition.y + y * 70));
            i++;
        }
    }
}

void EnemyHandler::Update()
{
    int i = 0;
    for(int y = 0; y < enemyRows; y++)
    {
        for(int x = 0; x < enemyCount / enemyRows; x++)
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
                    enemySpeed = enemySpeed + 0.001f;
                    ptrStarfield -> SpeedUp();
                }
                
                if(isMovingRight == false)
                    enemyAnchorPosition.x = enemyAnchorPosition.x - enemySpeed;
                if(enemyAnchorPosition.x < 0.f)
                {
                    isMovingRight = true;
                    enemyAnchorPosition.y += 8.f;
                    enemyAnchorPosition.x = 1.f;
                    enemySpeed = enemySpeed + 0.001f;
                    ptrStarfield -> SpeedUp();
                }
                enemyList[i].SetPosition(sf::Vector2f(enemyAnchorPosition.x + x * 70, enemyAnchorPosition.y + y * 70));
                enemyList[i].DrawSprite();
                i++;
            }
            
            
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
