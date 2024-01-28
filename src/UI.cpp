#include "Global.hpp"

#include "raylib.h"
#include "UI.hpp"

int UI::loadSprite(const std::string& path)
{
	mainSprite = LoadTexture(path.c_str());
	if (mainSprite.id == 0)
		throw std::runtime_error("Error: Failed to load texture");
	source = {0.0f, 0.0f, static_cast<float>(mainSprite.width), static_cast<float>(mainSprite.height)};
	dest = {0.0f, 0.0f, static_cast<float>(mainSprite.width), static_cast<float>(mainSprite.height)};
	origin = {0.0f, 0.0f};
	rotation = 0.0f;
	color = WHITE;
	return (0);
}

int UI::loadSprite(Texture2D texture)
{
	mainSprite = texture;
	if (mainSprite.id == 0)
		throw std::runtime_error("Error: Failed to load texture");
	source = {0.0f, 0.0f, static_cast<float>(mainSprite.width), static_cast<float>(mainSprite.height)};
	dest = {0.0f, 0.0f, static_cast<float>(mainSprite.width), static_cast<float>(mainSprite.height)};
	origin = {0.0f, 0.0f};
	rotation = 0.0f;
	color = WHITE;
	return (0);
}


UI::~UI()
{
	if (mainSprite.id != 0)
	{
		std::cout << "Texture unloaded" << std::endl; // "Texture unloaded
		UnloadTexture(mainSprite);
	}
}