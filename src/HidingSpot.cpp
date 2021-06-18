
#include <SFML/Graphics.hpp>
#include <iostream>
#include "hidingspot.hpp"

using namespace std;

void EnemyHandler::Init(sf::RenderWindow *prtWindow)
{
    enemyCount = 50;
    enemyRows = 5;
    enemyList = std::vector<EnemyModel>(enemyCount);
    ptrStarfield = starsRef;
    enemySpeed = 0.4f;
    isMovingRight = true;
    if (!enemyTexture.loadFromFile("data/sprites/alien1.png"))
    {
        // error...
    }
    int i = 0;
    int multiplierIndex = enemyRows;
    for(int y = 0; y < enemyRows; y++)
    {
        for(int x = 0; x < enemyCount / enemyRows; x++)
        {
            enemyList.at(i).Spawn(prtWindow, &enemyTexture, multiplierIndex);
            enemyList.at(i).SetPosition(sf::Vector2f(x * 64 + enemyList.at(i).GetSpriteSize(), y * 48 + enemyList.at(i).GetSpriteSize() + 64));
            i++;
            //cout << "Enemy Index = " << to_string(i) << endl;
        }
        multiplierIndex--;
    }
}

void EnemyHandler::Update()
{
    int globalEnemyIndex = 0;
    for(int y = 0 ; y < enemyRows; y++)
    {
        for(int x = 0; x < enemyCount / enemyRows; x++)
        {
            if(enemyList.at(globalEnemyIndex).isAlive == true)
            {
                if(enemyList.at(globalEnemyIndex).GetPosition().x >= 800-enemyList.at(globalEnemyIndex).GetSpriteSize())
                {
                    isMovingRight = false;
                    LowerEnemies();
                }
                if(enemyList.at(globalEnemyIndex).GetPosition().x <= 0)
                {
                    isMovingRight = true;
                    LowerEnemies();
                }

                if(isMovingRight == true)
                    enemyList.at(globalEnemyIndex).SetPosition(sf::Vector2f(enemyList.at(globalEnemyIndex).GetPosition().x + enemySpeed, enemyList.at(globalEnemyIndex).GetPosition().y));
                if(isMovingRight == false)
                    enemyList.at(globalEnemyIndex).SetPosition(sf::Vector2f(enemyList.at(globalEnemyIndex).GetPosition().x - enemySpeed, enemyList.at(globalEnemyIndex).GetPosition().y));
                enemyList.at(globalEnemyIndex).DrawSprite();
            }
            globalEnemyIndex++;
        }
    }
}

void EnemyHandler::LowerEnemies()
{
    for(int globalEnemyIndex = 0; globalEnemyIndex < enemyCount; globalEnemyIndex++)
    {
        enemyList.at(globalEnemyIndex).SetPosition(sf::Vector2f(enemyList.at(globalEnemyIndex).GetPosition().x, enemyList.at(globalEnemyIndex).GetPosition().y + 8));
    }
}

int EnemyHandler::CheckForCollision(sf::Vector2f shotPos)
{
    for(int globalEnemyIndex = 0; globalEnemyIndex < enemyCount; globalEnemyIndex++)
    {
        EnemyModel e = enemyList.at(globalEnemyIndex);
        if(e.isAlive == true)
        {
            sf::Vector2f ePos = e.GetPosition();
            if(shotPos.x >= ePos.x && shotPos.x <= ePos.x + e.GetSpriteSize())
            {
                if(shotPos.y >= ePos.y && shotPos.y <= ePos.y + e.GetSpriteSize())
                {
                    enemyList.at(globalEnemyIndex).Die();
                    enemySpeed+=0.007f;
                    return enemyList.at(globalEnemyIndex).GetRowIndex() * 10;
                }
            }    
        }
    }
    return -1;
}
