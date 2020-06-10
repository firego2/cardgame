#pragma once
#include "GameObject.h"


class Background : public GameObject
{
public:
	Background(const char* name_in_map) : GameObject(SDL_Rect{ 0, 0, GLBL::BACKGROUND_SRC_WIDTH, GLBL::BACKGROUND_SRC_HEIGHT }, 
		                                             SDL_Rect{ 0, 0, GLBL::SCREEN_WIDTH, GLBL::SCREEN_HEIGHT }, name_in_map, 0) {}
	virtual void update() {}

private:

};

