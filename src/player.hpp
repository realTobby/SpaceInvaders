// player.hpp
#include "drawable.hpp"

#ifndef PlayerModel_h
#define PlayerModel_h

class PlayerModel : public DrawableModel
{
	private:
		sf::RectangleShape shotShape;
		
        sf::Vector2f shotPosition;
        float playerSpeed;

        void shoot();

	public:
		bool canShoot;
		void Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture);
		void Update();
	    sf::Vector2f GetShotPosition();
};
#endif