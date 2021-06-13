#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemyhandler.hpp"

using namespace std;

void EnemyHandler::Init(sf::RenderWindow *prtWindow, Starfield *starsRef)
{
    enemyCount = 40;
    enemyRows = 4;
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
            enemyList.at(i).Spawn(prtWindow, &enemyTexture);
            enemyList.at(i).SetPosition(sf::Vector2f(enemyAnchorPosition.x + x * 68, enemyAnchorPosition.y + y * 64));
            i++;
            //cout << "Enemy Index = " << to_string(i) << endl;
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
            if(enemyList.at(i).isAlive == true)
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
                enemyList.at(i).SetPosition(sf::Vector2f(enemyAnchorPosition.x + x * 70, enemyAnchorPosition.y + y * 70));
                enemyList.at(i).DrawSprite();
                
            }
            i++;
            
        }
    }
}

bool EnemyHandler::CheckForCollision(sf::Vector2f shotPos)
{
    for(int i = 0; i < enemyCount; i++)
    {
        EnemyModel e = enemyList.at(i);
        if(e.isAlive == true)
        {
            sf::Vector2f ePos = e.GetPosition();
            if(shotPos.x >= ePos.x && shotPos.x <= ePos.x + 64)
            {
                if(shotPos.y >= ePos.y && shotPos.y <= ePos.y + 64)
                {
                    enemyList.at(i).Die();
                    return true;
                }
            }    
        }
    }
    return false;
}
