// player.hpp
#ifndef PlayerModel_h
#define PlayerModel_h

class PlayerModel
{
	private:
		sf::RenderWindow *windowPointer;
		sf::Vector2f Position;
		sf::RectangleShape playerShape;
		bool canShoot;
        sf::Vector2f shotPosition;
        float playerSpeed;

	public:
		void Init(sf::RenderWindow *ptrWindow);
		void Draw();
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f pos);
		void Update();
};
#endif