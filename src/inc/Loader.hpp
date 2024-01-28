#pragma once

#include "Global.hpp"

#include "raylib.h"
#include "UI.hpp"
#include "Button.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Loader
{
	public:
		static void MenuButtons(UI *ui[]);
		static void MapTiles(Map *map);
		static void PlayerStart(Player *player);
};