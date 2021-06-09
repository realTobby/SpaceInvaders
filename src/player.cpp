#include <SFML/Graphics.hpp>
#include "player.hpp"

void PlayerModel::Init(sf::RenderWindow *ptrWindow)
{
	windowPointer = ptrWindow;

	playerShape = sf::RectangleShape(sf::Vector2f(48.f,48.f));
    playerShape.setFillColor(sf::Color::Green);
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
        canShoot = false;
    }

    if(canShoot == false)
    {

    }
    Draw();
}
