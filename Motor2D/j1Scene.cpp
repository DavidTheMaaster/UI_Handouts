#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "j1Scene.h"
#include "j1Fonts.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	



	SDL_Texture *Background,*blizzard, *pegi, *logo, *button, *small_button,*dialog;

	Background = App->tex->Load("textures/login_background.png");
	blizzard = App->tex->Load("textures/Glues-BlizzardLogo.png");
	pegi = App->tex->Load("textures/Glues-FrenchRating.png");
	logo = App->tex->Load("textures/wow_logo.png");
	button = App->tex->Load("textures/button.png");
	small_button = App->tex->Load("textures/small_button.png");
	dialog = App->tex->Load("textures/dialog_button.png");



	

	SDL_Rect r;
	r.x = r.y = 0; 
	r.w = r.h = 100;

	//IMAGES
	App->gui->AddImage(0, 0, Background);
	App->gui->AddImage(712, 840, blizzard);
	App->gui->AddImage(19, 863, pegi);
	App->gui->AddImage(16, 12, logo);

	//BUTTONS
	App->gui->AddImage(20, 690, small_button);
	App->gui->AddImage(20, 735, small_button);
	App->gui->AddImage(20, 780, small_button);
	App->gui->AddImage(20, 825, small_button);
	App->gui->AddImage(1390, 600, small_button);
	App->gui->AddImage(1390, 645, small_button);
	App->gui->AddImage(1390, 690, small_button);
	App->gui->AddImage(1390, 735, small_button);
	App->gui->AddImage(1390, 900, small_button);

	
	App->gui->AddImage(666, 708, button);
	App->gui->AddImage(666, 490, dialog);
	App->gui->AddImage(666, 580, dialog);



	//VERY VERY VERY WRONG, JUST SOME TESTS
	App->gui->AddLabel(635, 944, "Copyright 2004-2012 Blizzard Entertainment. All Rights Reserved", BLACK, ARIALN, 12);
	App->gui->AddLabel(635, 946, "Copyright 2004-2012 Blizzard Entertainment. All Rights Reserved", BLACK, ARIALN, 12);
	App->gui->AddLabel(634, 945, "Copyright 2004-2012 Blizzard Entertainment. All Rights Reserved", BLACK, ARIALN, 12);
	App->gui->AddLabel(636, 945, "Copyright 2004-2012 Blizzard Entertainment. All Rights Reserved", BLACK, ARIALN, 12);

	//TEXT
	App->gui->AddLabel(635, 945, "Copyright 2004-2012 Blizzard Entertainment. All Rights Reserved", YELLOW, ARIALN, 12);
	App->gui->AddLabel(56, 692, "Language", YELLOW, MORPHEUS, 12);
	App->gui->AddLabel(40, 737, "Create Account", YELLOW, MORPHEUS, 12);
	App->gui->AddLabel(52, 782, "My Account", YELLOW, MORPHEUS, 12);
	App->gui->AddLabel(53, 827, "Official Site", YELLOW, MORPHEUS, 12);
	App->gui->AddLabel(4, 931, "Version 5.0.1 (15726) (Beta x64)", BLACK, MORPHEUS, 12);
	App->gui->AddLabel(3, 930, "Version 5.0.1 (15726) (Beta x64)", YELLOW, MORPHEUS, 12);
	App->gui->AddLabel(4, 945, "May 21 2012", BLACK, MORPHEUS, 12);
	App->gui->AddLabel(3, 944, "May 21 2012", YELLOW, MORPHEUS, 12);

	App->gui->AddLabel(671, 469, "Battle.net Account Name", BLACK, MORPHEUS, 15);
	App->gui->AddLabel(670, 468, "Battle.net Account Name", YELLOW, MORPHEUS, 15);

	App->gui->AddLabel(736, 558, "Password", BLACK, MORPHEUS, 15);
	App->gui->AddLabel(735, 557, "Password", YELLOW, MORPHEUS, 15);

	App->gui->AddLabel(752, 709, "Login", YELLOW, MORPHEUS, 15);










	// TODO 3: Create the banner (rect {485, 829, 328, 103}) and the text "Hello World"

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);

	if(App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		if(origin_selected == true)
		{
			App->pathfinding->CreatePath(origin, p);
			origin_selected = false;
		}
		else
		{
			origin = p;
			origin_selected = true;
		}
	}

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	// Gui ---
	
	// -------
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);

	App->map->Draw();

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count(),
					map_coordinates.x, map_coordinates.y);

	//App->win->SetTitle(title.GetString());

	// Debug pathfinding ------------------------------
	//int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);
	p = App->map->MapToWorld(p.x, p.y);

	App->render->Blit(debug_tex, p.x, p.y);

	const p2DynArray<iPoint>* path = App->pathfinding->GetLastPath();

	for(uint i = 0; i < path->Count(); ++i)
	{
		iPoint pos = App->map->MapToWorld(path->At(i)->x, path->At(i)->y);
		App->render->Blit(debug_tex, pos.x, pos.y);
	}

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
