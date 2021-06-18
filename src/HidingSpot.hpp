// HidingSpot.hpp
#include "drawable.hpp"
#ifndef HidingSpot_h
#define HidingSpot_h

class HidingSpot : public DrawableModel
{
	public:
		HidingSpot();
		void Init(sf::RenderWindow *ptrWindow, sf::Texture *ptrTexture);
};
#endif