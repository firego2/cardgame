#pragma once
#include "GameState.h"

class IntroState : public GameState
{
public:
	IntroState(TextureManager* game_textures);
	void handleEvents();
	virtual void update(GameEngine* game);

private:
	virtual bool loadTextures();

};

