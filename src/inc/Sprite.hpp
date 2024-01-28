#pragma once

#include "Global.hpp"

#include "raylib.h"

class Sprite {
	public:
		Texture2D mainSprite;
		Rectangle source;
		Rectangle dest;
		Vector2 origin;
		float rotation;
		Color color;
	
		virtual int loadSprite(const std::string& path) = 0;
		virtual int loadSprite(Texture2D texture) = 0;
		virtual ~Sprite() { if (mainSprite.id != 0) UnloadTexture(mainSprite); };
};