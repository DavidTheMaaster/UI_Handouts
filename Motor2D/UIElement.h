#ifndef _UIElement_
#define _UIElement_

#include "SDL/include/SDL.h"
#include "p2Defs.h"
#include "p2Point.h"
#include "j1Textures.h"
#include "j1Gui.h"

enum UI_STATE {
	NO_STATE,
	MOUSE_ENTER,
	MOUSE_LEAVE,
	L_MOUSE_PRESSED,
	R_MOUSE_PRESSED,
	FOCUSED,
};

class UIElement
{

public:

	SDL_Rect rect;
	iPoint pos;
	uint w;
	uint h;

	j1Module* callback = nullptr;

	UI_TYPE type;
	UI_STATE state;

	const SDL_Texture *texture = nullptr;

public:

	UIElement(int x, int y, UI_TYPE type, const SDL_Texture* texture);
	virtual ~UIElement() { };

	virtual void Draw(float dt);
	virtual void Update(float dt);

};



#endif
