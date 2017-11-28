#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"

UIElement::UIElement(int x, int y, const SDL_Texture* texture)
{
	this->texture = texture;
	App->tex->GetSize(texture, w, h);

	rect = { x,y,(int)w,(int)h };
}

void UIElement::Draw(float dt)
{
	App->render->Blit(texture, rect.x, rect.y, &rect);
}