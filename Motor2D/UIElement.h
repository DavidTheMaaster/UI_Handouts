#ifndef _UIElement_
#define _UIElement_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"

class UIElement
{
public:

	UIElement(int, int, const SDL_Texture*);
	virtual ~UIElement() { };

	//virtual void Update(float dt) { };
	virtual void Draw(float);
	
public:

	SDL_Rect rect;
	uint w;
	uint h;

	const SDL_Texture *texture = nullptr;
};



#endif
