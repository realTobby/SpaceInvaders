// enemy.hpp
#include "drawable.hpp"
#ifndef EnemyModel_h
#define EnemyModel_h

class EnemyModel : public DrawableModel
{
	private:
		sf::Vector2f Position;
		sf::Vector2f enemyAnchorPosition;

	public:
		EnemyModel();
		void Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture);
};
#endif