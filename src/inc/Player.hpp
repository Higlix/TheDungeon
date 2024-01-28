#pragma once
#include "Global.hpp"

#include "raylib.h"
#include "Entity.hpp"
#include "Map.hpp"

class Player : public Entity {
	public:
		Vector2 position;
		std::vector<Rectangle> spriteList;
		Rectangle attackArea;
		Rectangle hitBox;
		bool hit;
		float snapSpriteWidth;
		float scale;
		bool dash;

		/* tmP*/
		int level;
		bool moving;

		void update();
		void update(void (*f)(void *), void *args);
		void input(void (*f)(void *), void *args);
		void drawRec() const;
		void drawCustom(void (*f)(void *), void *args) const;
		Player();
		~Player();
};

class Test {
	public:
		Player *player;
		Map *map;
};

bool checkColl(Rectangle player, std::vector<Rectangle> solids);
void playerInput(void *args);
void movePlayer(void *args);