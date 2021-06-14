// drawable.hpp
#ifndef Drawable_h
#define Drawable_h

class DrawableModel
{
	private:
		sf::RenderWindow *windowPointer;
		sf::Texture *ptrTexture;
		sf::Sprite sprite;
		sf::Vector2f Position;

	public:
		void Init(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture);
		void DrawSprite();
		void DrawShape(sf::RectangleShape shapeToDraw);
		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f pos);
		int GetSpriteSize();
};
#endif