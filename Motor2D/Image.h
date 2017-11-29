#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "UIElement.h"
#include "SDL\include\SDL.h"
#include "p2Defs.h"
#include "p2Point.h"

class Image : public UIElement
{
public:
	Image(uint pos_x, uint pos_y,  SDL_Texture* texture);
};



#endif // !_LABEL_H__

