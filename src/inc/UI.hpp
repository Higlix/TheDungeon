#pragma once

#include "Global.hpp"

#include "raylib.h"
#include "Sprite.hpp"

class UI : public Sprite {
	public:
		int loadSprite(const std::string& path) override;
		int loadSprite(Texture2D texture) override;
		virtual void drawRec(void) const = 0;
		virtual void update() = 0;
		virtual void update(void (*f)(void *), void *args) = 0;
		virtual ~UI();
};