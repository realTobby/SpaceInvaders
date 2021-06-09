#include <SFML/Graphics.hpp>
#include "player.hpp"

void PlayerModel::Init(sf::RenderWindow *ptrWindow)
{
	windowPointer = ptrWindow;

	playerShape = sf::RectangleShape(sf::Vector2f(48.f,48.f));
    playerShape.setFillColor(sf::Color::Green);

    shotShape = sf::RectangleShape(sf::Vector2f(10.f,20.f));

    playerSpeed = 0.09f;
    canShoot = true;
    SetPosition(sf::Vector2f(400.f,500.f));
    
}

void PlayerModel::Draw()
{
	windowPointer -> draw(playerShape);
}

sf::Vector2f PlayerModel::GetPosition()
{
	return Position;
}

void PlayerModel::SetPosition(sf::Vector2f pos)
{
	Position = pos;
	playerShape.setPosition(Position);
}

void PlayerModel::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Position.x > 0)
    {
        // move left...
        //cout << "Move Left..." << endl;
        sf::Vector2f newPos = GetPosition();
        newPos.x -= 0.09f; // ==> ???? Wenn ich hier playerSpeed als Variable eintrage dann bewegt sich der Player nicht mehr???  !!!!!!
        SetPosition(newPos);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Position.x < 800-48)
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
        windowPointer -> draw(shotShape);

        if(shotPosition.y < 0)
            canShoot = true;
    }
    Draw();
}

void PlayerModel::shoot()
{
    shotPosition.x = GetPosition().x + 16.f;
    shotPosition.y = GetPosition().y;
    canShoot = false;
}