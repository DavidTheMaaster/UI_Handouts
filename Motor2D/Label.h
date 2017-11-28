#ifndef _LABEL_H_
#define _LABEL_H_

#include "UIElement.h"
#include "SDL\include\SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class Label : public UIElement
{
public:
	Label(uint pos_x, uint pos_y, const SDL_Texture* texture);
};



#endif // !_LABEL_H__

