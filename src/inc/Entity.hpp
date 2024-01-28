#pragma once
#include "Global.hpp"

#include "raylib.h"
#include "Sprite.hpp"

class Entity : public Sprite {
	public:
		Vector2 position;

		int loadSprite(const std::string& path) override;
		int loadSprite(Texture2D texture) override;
		virtual void update() = 0;
		virtual void update(void (*f)(void *), void *args) = 0;
		virtual void drawRec() const = 0;
		virtual ~Entity();
		Entity();
};