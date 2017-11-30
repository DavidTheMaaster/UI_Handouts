#include "Label.h"
#include "j1App.h"
#include "j1Gui.h"

Label::Label(uint pos_x, uint pos_y, UI_TYPE type, const SDL_Texture * texture) : UIElement(pos.x, pos.y, type, texture)
{
	pos.x = pos_x;
	pos.y = pos_y;
}

