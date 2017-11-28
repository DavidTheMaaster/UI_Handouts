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
/*
Image* j1Gui::AddImage(iPoint position, SDL_Rect rect, const SDL_Texture* texture)
{
	Image* new image = new Image(position.x, position.y, rect, texture);
	elements.add((UIElement*)image);

	return image;
}
*/

Label* j1Gui::AddLabel(int x, int y, char* text, SDL_Color color, _TTF_Font* font)
{
	const SDL_Texture* tex = App->font->Print(text, color, font);
	
	Label* label = new Label(x, y, tex);
	elements.add((UIElement*)label);

	return label;
}
