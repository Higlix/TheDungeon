	#pragma	once

#include "Global.hpp"

#include "raylib.h"
#include "UI.hpp"

class Button : public UI {
	public:
		Rectangle hoverSprite;
		Rectangle clickSprite;
		Rectangle normalSprite;

		void drawRec(void) const override;
		void update(void) override;
		void update(void (*f)(void *), void *args) override;
		Button();
		~Button();
};