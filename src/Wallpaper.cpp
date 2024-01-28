#include "Global.hpp"

#include "raylib.h"
#include "Wallpaper.hpp"

int Wallpaper::loadSprite(const std::string& path)
{
	mainSprite = LoadTexture(path.c_str());
	source = { 0.0f, 0.0f, (float)mainSprite.width, (float)mainSprite.height };
	dest = { 0.0f, 0.0f, _WIN_SCALE_ * _MIN_WIDTH_, _WIN_SCALE_ * _MIN_HEIGHT_ };
	origin = { 0.0f, 0.0f };
	rotation = 0.0f;
	color = WHITE;
	return 0;
}

int Wallpaper::loadSprite(Texture2D texture)
{
	mainSprite = texture;
	source = { 0.0f, 0.0f, (float)mainSprite.width, (float)mainSprite.height };
	dest = { 0.0f, 0.0f, _WIN_SCALE_ * _MIN_WIDTH_, _WIN_SCALE_ * _MIN_HEIGHT_ };
	origin = { 0.0f, 0.0f };
	rotation = 0.0f;
	color = WHITE;
	return 0;
}

void Wallpaper::drawRec(void) const
{
	DrawTexturePro(mainSprite, source, dest, origin, rotation, color);
}

Wallpaper::~Wallpaper()
{
	std::cout << "Wallpaper destructor called" << std::endl; // "Wallpaper destructor called
	if (mainSprite.id != 0)
		UnloadTexture(mainSprite);
}