// enemy.hpp
#ifndef EnemyModel_h
#define EnemyModel_h

class EnemyModel
{
	private:
		sf::RenderWindow *windowPointer;
		sf::Vector2f Position;
		sf::RectangleShape enemyShape;

	public:
		EnemyModel();
		void Spawn(sf::RenderWindow *ptrWindow);
		void Draw();
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f pos);

};
#endif