#include "Global.hpp"

#include "raylib.h"
#include "Sprite.hpp"
#include "Scene.hpp"
#include "Button.hpp"
#include "Wallpaper.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include "Utils.hpp"
#include "Render.hpp"
#include "Loader.hpp"
#include "Input.hpp"

static void CreateWindow(void);

void test(void *args)
{
	Scene *scene = (Scene *)args;
	scene->currentSceneID = _GAME_ID_;
	std::cout << "test" << std::endl;
}

void test2(void *args)
{
	Scene *scene = (Scene *)args;
	scene->currentSceneID = _MENU_ID_;
	std::cout << "test2" << std::endl;

}

void test3(void *args)
{
	bool *isRunning = (bool *)args;
	*isRunning = false;
}

void playerDash(void *args)
{
	Test *t = (Test *)args;
	Player *player = t->player;
	Map *map = t->map;
	static int i;
	float oldPos;

	if (!i)
		i = 1;
	else if (i <= 1000)
	{
		player->color = (Color){ 0, 0, 0, 125 };

			oldPos = player->position.y;
			player->position.y += 300.0f * GetFrameTime();
			player->dest.y = player->position.y;
			player->hitBox.y = player->position.y + ((_WIN_SCALE_ - 2) * 8);
			if (!checkColl(player->hitBox, map->solids))
			{
				player->position.y = oldPos;
				player->dest.y = oldPos;
				player->hitBox.y = oldPos + ((_WIN_SCALE_ - 2) * 8);
				// i = 1000;
			}
	}
	else
	{
		player->color = (Color){ 255, 255, 255, 255 };
		player->dash = false;
		i = 1;
	}
	i++;	
}

int main(void)
{
	try
	{
		// SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
		CreateWindow();

		Scene scene;
		scene.currentSceneID = _GAME_ID_;

		UI *a[5];
		Loader::MenuButtons(a);

		Map map;
		Loader::MapTiles(&map);

		Player player;
		Loader::PlayerStart(&player);

		player.dash = false;

		Wallpaper wp;
		wp.loadSprite("res/wallpaper.png");

		bool isRunning = true;

		Test t;

		t.map = &map;
		t.player = &player;


		// std::thread th(check, &data);
		// std::thread th(check, a);
		// std::thread th(check, &t);

		// SetExitKey(KEY_NULL);

		while (!WindowShouldClose() && isRunning)
		{
			/* INPUT FIRST */
			if (!player.dash)
				player.input(playerInput, &t);
			else
				player.input(playerDash, &t);

			
			switch(scene.currentSceneID)
			{
				case _MENU_ID_:
					/* UPDATE */
					a[0]->update(test, &scene);
					for (int i = 1; i < 3; i++)
					{
						a[i]->update();
					}
					a[3]->update(test3, &isRunning);

					/* DRAW */
					BeginDrawing();
						wp.drawRec();
						for (int i = 0; i < 4; i++)
						{
							a[i]->drawRec();
						}
						DrawText("Menu", 10, 10, 20, BLACK);
						DrawFPS(5, 35);
					EndDrawing();
				break;
				
				case _GAME_ID_:
					/* UPDATE */
					a[4]->update(test2, &scene);
					player.update(movePlayer, &player);

					/* DRAW */
					BeginDrawing();
						ClearBackground(BLACK);
						//DrawRectanglePro(player.dest, Vector2{0, 0}, 0.0f, BLUE);

						Render::RenderMapWithPlayer(map, player);
						if (player.hit)
						{
							DrawRectangle(
								player.attackArea.x,
								player.attackArea.y,
								player.attackArea.width,
								player.attackArea.height,
								RED
							);
						}
						
						a[4]->drawRec();
						DrawText("Game", 10, 10, 20, BLACK);
						DrawFPS(5, 35);
					EndDrawing();
				break;
			}
		}
		for(int i = 0; i < 5; i++)
		{
			delete a[i];
		}
		CloseWindow();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
    return (0);
}

static void CreateWindow(void)
{
	InitWindow(_MIN_WIDTH_ * _WIN_SCALE_, _MIN_HEIGHT_ * _WIN_SCALE_, _TITLE_);
	if (IsWindowReady() == false)
		throw std::runtime_error("Failed to create window");
	SetWindowMinSize(_MIN_WIDTH_, _MIN_HEIGHT_);
	SetTargetFPS(1000);
}