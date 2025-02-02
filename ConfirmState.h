#pragma once
#include "GameState.h"

class ConfirmState : public GameState
{
public:
	ConfirmState(TextureManager* game_textures);
	virtual void update(GameEngine* game);
	virtual void handleEvents();
	virtual void render();

private:
	virtual bool loadTextures();
};

