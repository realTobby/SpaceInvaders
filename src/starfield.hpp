// Starfield.hpp
#ifndef Starfield_h
#define Starfield_h

class Starfield
{
	private:

		sf::RenderWindow *windowPointer;
		sf::Vector2f Position;
		sf::Vector2f starLayer1[100];
        sf::Vector2f starLayer2[100];
        sf::Vector2f starLayer3[100];
        sf::RectangleShape starShape;
        float starSpeed1;
        float starSpeed2;
        float starSpeed3;

	public:
		void Init(sf::RenderWindow *ptrWindow);
		void Draw();
		void Update();
		void SpeedUp();
};
#endif