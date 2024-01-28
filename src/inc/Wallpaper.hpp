#pragma once

#include "Global.hpp"

#include "raylib.h"
#include "Sprite.hpp"

class Wallpaper : public Sprite{
	public:
		int loadSprite(const std::string& path) override;
		int loadSprite(Texture2D texture) override;
		void drawRec(void) const;
		~Wallpaper();
};