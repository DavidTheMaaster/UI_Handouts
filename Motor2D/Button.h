#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "UIElement.h"
#include "SDL\include\SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class Button : public UIElement
{
public:
	Button(uint pos_x, uint pos_y, UI_TYPE type, SDL_Texture* texture, j1Module* callback);
};



#endif // !_BUTTON_H__
