#include "Map.hpp"

Map::Map()
{

}

Map::~Map()
{
	if (mainSprite.id != 0)
	{
		std::cout << "Texture unloaded" << std::endl; // "Texture unloaded
		UnloadTexture(mainSprite);
	}
}

void Map::drawRec() const
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

void Map::drawSep(Rectangle src, Rectangle dst) const
{
	Rectangle n = dst;

	n.x *= _WIN_SCALE_;
	n.y *= _WIN_SCALE_;
	n.width *= _WIN_SCALE_;
	n.height *= _WIN_SCALE_;

	DrawTexturePro(
		mainSprite, 
		src, 
		n, 
		origin, 
		rotation, 
		color
	);
}

int Map::loadSprite(const std::string& path)
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

int Map::loadSprite(Texture2D texture)
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
