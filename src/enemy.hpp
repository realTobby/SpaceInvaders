// enemy.hpp
#include "drawable.hpp"
#ifndef EnemyModel_h
#define EnemyModel_h

class EnemyModel : public DrawableModel
{
	private:
		sf::Vector2f enemyAnchorPosition;
		int rowIndex = 0;


	public:
		bool isAlive;
		EnemyModel();
		void Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture, int rowI);
		void Die();
		int GetRowIndex();
};
#endif