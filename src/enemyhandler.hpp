#include "enemy.hpp"
#include "starfield.hpp"

// enemyhandler.hpp
#ifndef EnemyHandler_h
#define EnemyHandler_h

class EnemyHandler
{
	private:
		Starfield* ptrStarfield;
		EnemyModel enemyList[10];
		bool isMovingRight;
		sf::Vector2f enemyAnchorPosition;
		float enemySpeed;
		sf::Texture enemyTexture;

	public:
		void Init(sf::RenderWindow *ptrWindow, Starfield *starsRef);
		void Update();
};
#endif