#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "UIElement.h"
#include "Label.h"
#include "Image.h"
#include "j1Fonts.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


	const SDL_Texture* GetAtlas() const;

	// TODO 2: Create the factory methods
	// Gui creation functions
	bool Update(float dt);

	Label* AddLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font);
	Image* AddImage(int x, int y, SDL_Texture* texture, SDL_Rect Animation);

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2List<UIElement*> elements;

};

#endif // __j1GUI_H__