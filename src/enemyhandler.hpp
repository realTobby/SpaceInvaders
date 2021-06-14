#include "enemy.hpp"
#include "starfield.hpp"


// enemyhandler.hpp
#ifndef EnemyHandler_h
#define EnemyHandler_h

class EnemyHandler
{
	private:
		Starfield* ptrStarfield;
		std::vector<EnemyModel> enemyList;
		bool isMovingRight;
		float enemySpeed;
		sf::Texture enemyTexture;
		int enemyCount;
		int enemyRows;
		void LowerEnemies();

	public:
		void Init(sf::RenderWindow *ptrWindow, Starfield *starsRef);
		void Update();
		int CheckForCollision(sf::Vector2f shotPosition);
};
#endif