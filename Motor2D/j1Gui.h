#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "UIElement.h"
#include "j1Fonts.h"

#define CURSOR_WIDTH 2

class Label;
class Image;
class Button;

// TODO 1: Create your structure of classes

// ---------------------------------------------------

enum COLOURS
{
	BLACK,
	WHITE,
	RED,
	BLUE,
	GREEN,
	YELLOW
};

enum FONTS
{
	ARIALN,
	FRIZQT,
	MORPHEUS,
	SKURRI
};

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
	
	Label* AddLabel(int x, int y, char* text, uint color, uint font, int size, UIElement* parent = nullptr);
	Image* AddImage(int x, int y, SDL_Texture* texture, UIElement* parent = nullptr);
	Button* AddButton(int x, int y, SDL_Texture* texture, j1Module* callback = nullptr, UIElement* parent = nullptr);
	SDL_Color GetColor(int color);
	char* GetFont(uint font);

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
	p2List<UIElement*> elements;

};

#endif // __j1GUI_H__