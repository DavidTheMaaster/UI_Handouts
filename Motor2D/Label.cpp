#include "Label.h"

Label::Label(uint pos_x, uint pos_y, const SDL_Texture * texture) : UIElement(pos.x, pos.y,texture)
{
	pos.x = pos_x;
	pos.y = pos_y;
}
