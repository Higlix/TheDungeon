#include "Global.hpp"

#include "raylib.h"
#include "Render.hpp"

void playerCustomDraw(void *args)
{
	Player *player = (Player *)args;

	DrawEllipse(
		player->hitBox.x + (player->hitBox.width / 2),
		player->hitBox.y + (player->hitBox.height - (player->hitBox.height / 12)),
		(player->hitBox.width / 2) - (player->hitBox.width / 15),
		player->hitBox.height / 4,
		(Color){ 0, 0, 0, 125 }	
	);
	player->drawRec();
}

void Render::RenderMapWithPlayer(Map &map, Player &player)
{
	map.drawSep(map.borders[0], map.borders[0]);
	map.drawSep(map.borders[1], map.borders[1]);
	map.drawSep(map.borders[2], map.borders[2]);
	map.drawSep(map.borders[5], map.borders[5]);
	player.drawCustom(playerCustomDraw, &player);
	map.drawSep(map.borders[3], map.borders[3]);
	map.drawSep(map.borders[4], map.borders[4]);
}