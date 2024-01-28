#include "Global.hpp"

#include "raylib.h"
#include "Input.hpp"

Input::Input()
{
	shiftMode = false;
	ctrlMode = false;
}

Input::~Input()
{
}

void Input::update(void)
{
	if ((IsKeyPressed(KEY_LEFT_SHIFT) || IsKeyPressed(KEY_RIGHT_SHIFT))
	|| (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)))
		shiftMode = true;
	else
		shiftMode = false;
	if ((IsKeyPressed(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_RIGHT_CONTROL))
	|| (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)))
		ctrlMode = true;
	else
		ctrlMode = false;
}