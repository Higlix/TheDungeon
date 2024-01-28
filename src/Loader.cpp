#include "Global.hpp"

#include "raylib.h"

#include "Loader.hpp"

void Loader::PlayerStart(Player *player)
{
	player->loadSprite("res/Puny-Characters/Mage-Red.png");

	player->scale = _WIN_SCALE_ - 2;
	float tmp = player->dest.width / 24;;
	int scale = player->scale;

	player->position.x = _MIDDLE_X_;
	player->position.y = _MIDDLE_Y_;
	player->snapSpriteWidth = tmp;
	player->hit = false;
	player->attackArea.x = tmp;
	player->attackArea.y = 0;
	player->attackArea.width = tmp / 2 * scale;
	player->attackArea.height = (player->dest.height / 8) * scale;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 1; x < 4; x++)
		{
			Rectangle newSprite;
			newSprite.height = 32;
			newSprite.width = 32;
			newSprite.x = 32 * x;
			newSprite.y = 32 * y;
			player->spriteList.push_back(newSprite);
		}
	}
	player->spriteList.push_back(Rectangle{0, 0, 32, 32});
	for (int i = 0; i < player->spriteList.size(); i++)
		std::cout << player->spriteList[i].x << std::endl;
	player->source = player->spriteList[0];
	player->dest.height = 32 * scale;
	player->dest.width = 32 * scale;
	player->hitBox.width = 16 * scale;
	player->hitBox.height = 16 * scale;
	player->hitBox.x = player->position.x + ((_WIN_SCALE_ - 2) * 8);
	player->hitBox.y = player->position.y + ((_WIN_SCALE_ - 2) * 8);
}

void Loader::MapTiles(Map *map)
{
	float h = _WIN_SCALE_ * _MIN_HEIGHT_;
	float w = _WIN_SCALE_ * _MIN_WIDTH_;


	map->loadSprite("res/TestMap1.png");
	map->dest.x = 0;
	map->dest.y = 0;
	map->dest.width = w;
	map->dest.height = h;

	/* TOP WALL */
	map->solids.push_back(Rectangle{
		0 * _WIN_SCALE_,
		0 * _WIN_SCALE_,
		256 * _WIN_SCALE_,
		15 * _WIN_SCALE_
	});

	/* LEFT WALL */
	map->solids.push_back(Rectangle{
		0 * _WIN_SCALE_,
		0 * _WIN_SCALE_,
		4 * _WIN_SCALE_,
		180 * _WIN_SCALE_
	});
	/* BUTTOM WALL */
	map->solids.push_back(Rectangle{
		0 * _WIN_SCALE_,
		175 * _WIN_SCALE_,
		318 * _WIN_SCALE_,
		11 * _WIN_SCALE_
	});

	/* RIGHT WALL */
	map->solids.push_back(Rectangle{
		315 * _WIN_SCALE_,
		15 * _WIN_SCALE_,
		4 * _WIN_SCALE_,
		164 * _WIN_SCALE_
	});

	/* DOOR */
	map->solids.push_back(Rectangle{
		252 * _WIN_SCALE_,
		15 * _WIN_SCALE_,
		66 * _WIN_SCALE_,
		15 * _WIN_SCALE_
	});

	/* CLOSE LEFT WALL */
	map->solids.push_back(Rectangle{
		252 * _WIN_SCALE_,
		0 * _WIN_SCALE_,
		5 * _WIN_SCALE_,
		26 * _WIN_SCALE_
	});

	/* SMALL ROOM TOP WALL */
	map->solids.push_back(Rectangle{
		190 * _WIN_SCALE_,
		82 * _WIN_SCALE_,
		87 * _WIN_SCALE_,
		5 * _WIN_SCALE_
	});	

	map->solids.push_back(Rectangle{
		190 * _WIN_SCALE_,
		138 * _WIN_SCALE_,
		87 * _WIN_SCALE_,
		5 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		176 * _WIN_SCALE_,
		97 * _WIN_SCALE_,
		13 * _WIN_SCALE_,
		4 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		177 * _WIN_SCALE_,
		122 * _WIN_SCALE_,
		12 * _WIN_SCALE_,
		4 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		277 * _WIN_SCALE_,
		74 * _WIN_SCALE_,
		5 * _WIN_SCALE_,
		66 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		229 * _WIN_SCALE_,
		83 * _WIN_SCALE_,
		48 * _WIN_SCALE_,
		8 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		185 * _WIN_SCALE_,
		74 * _WIN_SCALE_,
		5 * _WIN_SCALE_,
		26 * _WIN_SCALE_
	});

	map->solids.push_back(Rectangle{
		185 * _WIN_SCALE_,
		122 * _WIN_SCALE_,
		5 * _WIN_SCALE_,
		20 * _WIN_SCALE_
	});

}

void Loader::MenuButtons(UI *ui[])
{
	Texture2D texture = LoadTexture("res/gui.png");
	Button *a;
	float h = _WIN_SCALE_ * _MIN_HEIGHT_;
	float w = _WIN_SCALE_ * _MIN_WIDTH_;

	a = new Button;
	a->loadSprite(texture);
	a->source = {65 , 274, 46, 13};
	a->normalSprite = a->source;
	a->hoverSprite = {113, 274, 46, 13};
	a->clickSprite = {113, 290, 46, 13};
	a->dest = {w * 0.69f, h * 0.20f, 46 * _WIN_SCALE_ * 1.5, 13 * _WIN_SCALE_ * 1.5};
	a->color = WHITE;
	ui[0] = a;

	a = new Button;
	a->loadSprite(texture);
	a->source = {65 , 274, 46, 13};
	a->normalSprite = a->source;
	a->hoverSprite = {113, 274, 46, 13};
	a->clickSprite = {113, 290, 46, 13};
	a->dest = {w * 0.69f, h * 0.34f, 46 * _WIN_SCALE_ * 1.5, 13 * _WIN_SCALE_ * 1.5};
	a->color = WHITE;
	ui[1] = a;

	a = new Button;
	a->loadSprite(texture);
	a->source = {65 , 274, 46, 13};
	a->normalSprite = a->source;
	a->hoverSprite = {113, 274, 46, 13};
	a->clickSprite = {113, 290, 46, 13};
	a->dest = {w * 0.69f, h * 0.48f, 46 * _WIN_SCALE_ * 1.5, 13 * _WIN_SCALE_ * 1.5};
	a->color = WHITE;
	ui[2] = a;

	a = new Button;
	a->loadSprite(texture);
	a->source = {65 , 274, 46, 13};
	a->normalSprite = a->source;
	a->hoverSprite = {113, 274, 46, 13};
	a->clickSprite = {113, 290, 46, 13};
	a->dest = {w * 0.69f, h * 0.62f, 46 * _WIN_SCALE_ * 1.5, 13 * _WIN_SCALE_ * 1.5};
	a->color = WHITE;
	ui[3] = a;

	// GAME STAGE MENU BUTTON
	a = new Button;
	a->loadSprite(texture);
	a->source = {145 , 306, 14, 13};
	a->normalSprite = a->source;
	a->hoverSprite = a->source;
	a->clickSprite = {145, 322, 14, 13};
	a->dest = {w * 0.95f, h * 0.01f, 14 * _WIN_SCALE_, 13 * _WIN_SCALE_};
	a->color = WHITE;
	ui[4] = a;
}