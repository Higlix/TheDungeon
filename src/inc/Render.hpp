#pragma once
#include "Global.hpp"

#include "raylib.h"
#include "Map.hpp"
#include "Player.hpp"

class Render {
	public:
		static void RenderMapWithPlayer(Map &map, Player &player);
};