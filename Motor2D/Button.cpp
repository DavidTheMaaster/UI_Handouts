#include "Button.h"
#include "j1App.h"
#include "j1Gui.h"

Button::Button(uint x, uint y, UI_TYPE type, SDL_Texture * texture, j1Module* callback) : UIElement(pos.x, pos.y, type, texture)
{
	pos.x = x;
	pos.y = y;

	this->callback = callback;

}
