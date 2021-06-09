// enemy.hpp
#ifndef EnemyModel_h
#define EnemyModel_h

class EnemyModel
{
	private:
		sf::RenderWindow *windowPointer;
		sf::Texture *ptrTexture;
		sf::Vector2f Position;
		sf::Sprite sprite;
		bool isMovingRight = true;
		sf::Vector2f enemyAnchorPosition;

	public:
		EnemyModel();
		void Spawn(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture);
		void Draw();
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f pos);
};
#endif