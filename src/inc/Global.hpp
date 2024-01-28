#pragma once

#define _DEBUG_ 1

#define _TITLE_ "Game"

#define _MIN_WIDTH_ 320
#define _MIN_HEIGHT_ 180

// don't go above 5 while using macbook pro 13"
#define _WIN_SCALE_ 4

#define _MIDDLE_X_ (_WIN_SCALE_ * _MIN_WIDTH_) / 2
#define _MIDDLE_Y_ (_WIN_SCALE_ * _MIN_HEIGHT_) / 2

#define _MENU_ID_ 0
#define _GAME_ID_ 1

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <thread>
#include <iterator>

// #include <pthread>

// extern int WINWIDTH;
// extern int WINHEIGHT;
// extern std::string WINNAME;
