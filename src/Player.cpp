#include "Global.hpp"

#include "Player.hpp"
#include "Map.hpp"

Player::Player()
{
	this->position.x = 0;
	this->position.y = 0;
	this->spriteList.clear(); 
	this->scale = 1.0f;
	this->moving = false;
}

Player::~Player()
{
	this->spriteList.clear();
}

void Player::update()
{

}

void Player::update(void (*f)(void *), void *args)
{
	f(args);
}

void Player::input(void (*f)(void *), void *args)
{
	f(args);
}

void Player::drawRec() const
{
	DrawTexturePro(
		mainSprite, 
		source, 
		dest, 
		origin, 
		rotation, 
		color
	);
}

void Player::drawCustom(void (*f)(void *), void *args) const
{
	f(args);
}

void movePlayer(void *args)
{	
	int stage = 0;
	Player *player = (Player *) args;
	static clock_t now;
	double delay = 0.04 * CLOCKS_PER_SEC;

	if (!now)
		now = clock();
	if (player->moving)
	{
		if (clock() - now < delay)
		{
			stage = 0;
			player->source = player->spriteList[player->level * 3 + stage];
			std::cout << "FIRST SPRITE" << std::endl;
		}
		else if (clock() - now < delay * 2)
		{
			stage = 1;
			player->source = player->spriteList[player->level * 3 + stage];
			std::cout << "SECOND SPRITE" << std::endl;
		}
		else if (clock() - now < delay * 3)
		{
			stage = 2;
			player->source = player->spriteList[player->level * 3 + stage];
			std::cout << "THRID SPRITE" << std::endl;
		}
		else if (clock() - now < delay * 4)
		{
			now = clock();
		}
		player->moving = false;
	}
	else
	{
		delay = 0.08 * CLOCKS_PER_SEC;
		if (clock() - now < delay)
		{
			player->source = player->spriteList[player->spriteList.size() - 1];
			std::cout << "IDEAL 1" << std::endl;
		}
		else if (clock() - now < delay * 2)
		{
			stage = 0;
			player->source = player->spriteList[stage];
			std::cout << "IDEAL 2" << std::endl;
		}
		else if (clock() - now < delay * 3)
		{
			now = clock();
		}
	}
	// if (player->moving)
	// {
	// 	if (!i)
	// 	{
	// 		i = 1;
	// 	}
	// 	if (i <= 300)
	// 	{
	// 		stage = 0;
	// 		player->source = player->spriteList[player->level * 3 + stage];
	// 	}
	// 	else if (i <= 600)
	// 	{
	// 		stage = 1;
	// 		player->source = player->spriteList[player->level * 3 + stage];
	// 	}
	// 	else if (i <= 900)
	// 	{
	// 		stage = 2;
	// 		player->source = player->spriteList[player->level * 3 + stage];
	// 	}
	// 	else if (i <= 1500)
	// 	{
	// 		i = 1;
	// 	}
	// 	i+=2;
	// 	player->moving = false;
	// }
	// else
	// {
	// 	stage = 1;
	// 	player->source = player->spriteList[player->level * 3 + stage];
	// 	i = 1;
	// }
}

Rectangle scaleToCurrent(Rectangle solid)
{
	solid.x *= _WIN_SCALE_;
	solid.y *= _WIN_SCALE_;
	solid.height *= _WIN_SCALE_;
	solid.width *= _WIN_SCALE_;
	return (solid);
}

bool checkColl(Rectangle player, std::vector<Rectangle> solids)
{
	for (int i = 0; i < solids.size(); i++)
	{
		if (CheckCollisionRecs(player, scaleToCurrent(solids[i])))
			return (false);
	}
	return (true);
}

void playerInput(void *args)
{
	Test *test = (Test *)args;
	Map *map = test->map;
	Player *player = test->player;
	float oldPos;

	player->dest.x = player->position.x;
	player->dest.y = player->position.y;

	player->attackArea.y = player->position.y;
	if (IsKeyDown(KEY_A))
	{
		// for (int j = 0; j < 4; j++)
		// 	player->snaps[j].width = -player->snapSpriteWidth;
		player->moving = true;
		player->level = 6;
		player->source = player->spriteList[18];
		player->attackArea.x = player->position.x - player->attackArea.width;
		oldPos = player->position.x;
		player->position.x -= 300.0f * GetFrameTime();
		player->dest.x = player->position.x;
		player->hitBox.x = player->position.x + ((_WIN_SCALE_ - 2) * 8);
		if (!checkColl(player->hitBox, map->solids))
		{
			player->position.x = oldPos;
			player->dest.x = oldPos;
			player->hitBox.x = oldPos + ((_WIN_SCALE_ - 2) * 8);
		}
	}
	if (IsKeyDown(KEY_D))
	{
		player->moving = true;	
		player->level = 2;
		player->source = player->spriteList[6];
		player->attackArea.x = player->position.x + (player->dest.width);
		oldPos = player->position.x;
		player->position.x += 300.0f * GetFrameTime();
		player->dest.x = player->position.x;
		player->hitBox.x = player->position.x + ((_WIN_SCALE_ - 2) * 8);
		if (!checkColl(player->hitBox, map->solids))
		{
			player->position.x = oldPos;
			player->dest.x = oldPos;
			player->hitBox.x = oldPos + ((_WIN_SCALE_ - 2) * 8);
		}

	}
	if (IsKeyDown(KEY_W))
	{
		player->moving = true;
		player->level = 4;
		player->source = player->spriteList[12];
		oldPos = player->position.y;
		player->position.y -= 300.0f * GetFrameTime();
		player->dest.y = player->position.y;
		player->hitBox.y = player->position.y + ((_WIN_SCALE_ - 2) * 8);
		if (!checkColl(player->hitBox, map->solids))
		{
			player->position.y = oldPos;
			player->dest.y = oldPos;
			player->hitBox.y = oldPos + ((_WIN_SCALE_ - 2) * 8);
		}
	}
	if (IsKeyDown(KEY_S))
	{
		player->moving = true;
		player->level = 0;
		player->source = player->spriteList[0];
		oldPos = player->position.y;
		player->position.y += 300.0f * GetFrameTime();
		player->dest.y = player->position.y;
		player->hitBox.y = player->position.y + ((_WIN_SCALE_ - 2) * 8);
		if (!checkColl(player->hitBox, map->solids))
		{
			player->position.y = oldPos;
			player->dest.y = oldPos;
			player->hitBox.y = oldPos + ((_WIN_SCALE_ - 2) * 8);
		}
	}

	if (IsKeyPressed(KEY_LEFT_SHIFT))
	{
		player->dash = true;
	}

	if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
		player->level = 7;
	if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S))
		player->level = 1;
	if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
		player->level = 5;
	if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W))
		player->level = 3;


	if (IsKeyDown(KEY_SPACE))
		player->hit = true;
	else
		player->hit = false;
}
