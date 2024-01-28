#pragma once
#include "Global.hpp"

#include "raylib.h"

class Input {
	public:
		bool shiftMode;
		bool ctrlMode;

		Input();
		~Input();
		void update(void);
};