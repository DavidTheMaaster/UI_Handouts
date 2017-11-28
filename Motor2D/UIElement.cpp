#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"
#include "UIElement.h"

UIElement::UIElement(int x, int y, const SDL_Texture* texture)
{
	this->texture = texture;
	App->tex->GetSize(texture, w, h);

	pos.x = x;
	pos.y = y;

	rect = { x,y,(int)w,(int)h };
}

void UIElement::Draw(float dt)
{
	App->render->Blit(texture, pos.x, pos.y, &rect);
}