#pragma once
#include "Global.hpp"

#include "Sprite.hpp"
#include "raylib.h"

class Map : public Sprite {
	public:
		std::vector<Rectangle> solids;
		std::vector<Rectangle> breakables;
		std::vector<Rectangle> doors;
		std::vector<Rectangle> borders;
		std::vector<Rectangle> drawList;

		void drawRec() const;
		void drawSep(Rectangle src, Rectangle dst) const;
		int loadSprite(const std::string& path);
		int loadSprite(Texture2D texture);
		Map();
		~Map();
};