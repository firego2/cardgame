#pragma once
#include "GameObject.h"
class Smoke : public GameObject
{
public:
	Smoke(const char* name_in_map, int total_frame = 0) : GameObject(SDL_Rect{ 0, 0, GLBL::BACKGROUND_SRC_WIDTH, GLBL::BACKGROUND_SRC_HEIGHT },
		SDL_Rect{ 0, 0, GLBL::SCREEN_WIDTH, GLBL::SCREEN_HEIGHT }, name_in_map, total_frame), current_row(0), current_column(0) {}
	virtual void update();
private:
	int current_row;
	int current_column;
};

