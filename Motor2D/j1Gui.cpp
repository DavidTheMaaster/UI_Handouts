#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

bool j1Gui::Update(float dt)
{

	p2List_item<UIElement*> *it = elements.start;

	while (it != nullptr)
	{
		it->data->Draw(dt);
		it = it->next;
	}


	return true;

}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	elements.clear();
	
	App->tex->UnLoad(atlas);

	return true;
}
// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

Label* j1Gui::AddLabel(int x, int y, char* text, uint colors, uint fonts, int size)
{
	SDL_Color color;
	
	color = GetColor(colors);
	char* path = GetFont(fonts);
	_TTF_Font* font = App->font->Load(path, size);

	const SDL_Texture* tex = App->font->Print(text, color, font);
	
	Label* label = new Label(x, y, tex);
	elements.add((UIElement*)label);

	return label;
}


Image * j1Gui::AddImage(int x, int y, SDL_Texture* texture, SDL_Rect Animation)
{
	Image* image = new Image(x, y, texture, Animation);
	elements.add((UIElement*)image);

	return image;
}

SDL_Color j1Gui::GetColor(int color)
{
	SDL_Color ret;
	ret.a = 255;

	switch (color)
	{
	case BLACK:
		ret.r = 0;
		ret.g = 0;
		ret.b = 0;
		break;
	case WHITE:
		ret.r = 255;
		ret.g = 255;
		ret.b = 255;
		break;
	case RED:
		ret.r = 255;
		ret.g = 0;
		ret.b = 0;
		break;
	case BLUE:
		ret.r = 0;
		ret.g = 0;
		ret.b = 255;
		break;
	case GREEN:
		ret.r = 0;
		ret.g = 255;
		ret.b = 0;
		break;
	case YELLOW:
		ret.r = 255;
		ret.g = 255;
		ret.b = 0;
		break;
	default:
		break;
	}
	return ret;
}

char * j1Gui::GetFont(uint font)
{
	char* path = nullptr;
	switch (font)
	{
	case ARIALN:
		path = "fonts/arialn.ttf";
		break;
	case FRIZQT:
		path = "fonts/FRIZQT__.ttf";
		break;
	case MORPHEUS:
		path = "fonts/MORPHEUS.ttf";
		break;
	case SKURRI:
		path = "fonts/SKURRI.ttf";
		break;
	default:
		break;
	}
	return path;
}

