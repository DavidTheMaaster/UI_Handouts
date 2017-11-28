#include "Image.h"

Image::Image(uint x, uint y, SDL_Texture * texture, SDL_Rect Animation) : UIElement(pos.x, pos.y, texture)
{
	pos.x = x;
	pos.y = y;
}
