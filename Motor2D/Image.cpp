#include "Image.h"
#include "j1App.h"
#include "j1Gui.h"

Image::Image(uint x, uint y, UI_TYPE type, SDL_Texture * texture) : UIElement(pos.x, pos.y, type, texture)
{
	pos.x = x;
	pos.y = y;
}
