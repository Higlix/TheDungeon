#include "Global.hpp"

#include "raylib.h"
#include "UI.hpp"
#include "Button.hpp"

#define FONT_SIZE 35
#define FONT_SPACING 5

void Button::drawRec(void) const
{
	DrawTexturePro(
		mainSprite, 
		source, 
		dest, 
		origin, 
		rotation, 
		color
	);
}

void Button::update(void)
{
	if (CheckCollisionPointRec(GetMousePosition(), dest))
	{
		this->source = this->hoverSprite;
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			this->source = this->clickSprite;
	}
	else
		this->source = this->normalSprite;
}

void Button::update(void (*f)(void *), void *args)
{
	if (CheckCollisionPointRec(GetMousePosition(), dest))
	{
		this->source = this->hoverSprite;
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			this->source = this->clickSprite;
		else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			f(args);
	}
	else
		this->source = this->normalSprite;
}

Button::Button()
{
}

Button::~Button()
{
	std::cout << "Button destroyed" << std::endl;
}