// enemy.hpp
#ifndef EnemyModel_h
#define EnemyModel_h

class EnemyModel
{
	private:
		sf::Vector2f Position;

	public:
		EnemyModel();
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f pos);

};
#endif