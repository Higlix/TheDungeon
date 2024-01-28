#pragma once
#include "Global.hpp"

#include "Sprite.hpp"
#include "raylib.h"

class Map : public Sprite {
	public:
		std::vector<Rectangle> solids;

		void drawRec() const;
		int loadSprite(const std::string& path);
		int loadSprite(Texture2D texture);
		Map();
		~Map();
};