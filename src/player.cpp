#include <SFML/Graphics.hpp>
#include "player.hpp"

void PlayerModel::Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture)
{
	Init(ptrWindow, ptrTexture);

    shotShape = sf::RectangleShape(sf::Vector2f(10.f,20.f));

    playerSpeed = 0.09f;
    canShoot = true;
    SetPosition(sf::Vector2f(400.f,500.f));
    
}

void PlayerModel::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && GetPosition().x > 0)
    {
        // move left...
        //cout << "Move Left..." << endl;
        sf::Vector2f newPos = GetPosition();
        newPos.x -= 0.09f; // ==> ???? Wenn ich hier playerSpeed als Variable eintrage dann bewegt sich der Player nicht mehr???  !!!!!!
        SetPosition(newPos);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && GetPosition().x < 800-48)
    {
        // move right...
        //cout << "Move Right..." << endl;
        sf::Vector2f newPos = GetPosition();
        newPos.x += 0.09f; // ==> ???? Wenn ich hier playerSpeed als Variable eintrage dann bewegt sich der Player nicht mehr??? !!!!!!
        SetPosition(newPos);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot == true)
    {
        shotPosition = GetPosition();
        shoot();
    }

    if(canShoot == false)
    {
    	shotPosition.y = shotPosition.y - 0.25f;
        
        shotShape.setFillColor(sf::Color::Red);
        shotShape.setPosition(shotPosition);
        //windowPointer -> draw(shotShape);

        if(shotPosition.y < 0)
            canShoot = true;
    }
    DrawSprite();
}

void PlayerModel::shoot()
{
    shotPosition.x = GetPosition().x + 16.f;
    shotPosition.y = GetPosition().y;
    canShoot = false;
}