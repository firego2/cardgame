#pragma once
#include "IntroState.h"
#include "GameObject.h"
#include "Background.h"
#include "TextureManager.h"
#include "GameEngine.h"
#include "MenuState.h"
#include "Lightning.h"
#include <iostream>

IntroState::IntroState(TextureManager* game_textures) : GameState(game_textures)
{

	if (!loadTextures())
	{
		std::cerr << "Error loading texture!" << std::endl;
		throw 505;
	}
	std::cout << "Intro textures loaded successfully !" << std::endl;

	Background* background = new Background("intro");
	unused_state_objects.push_back(background);
	Lightning* lightning = new Lightning("lightning", GLBL::TOTAL_LIGHTNING_FRAME);
	unused_state_objects.push_back(lightning);
	std::cout << "IntroState make ok!" << std::endl;

}



void IntroState::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type)
		{
		case SDL_QUIT:
			GameState::game_quit();
			break;
		case SDL_MOUSEBUTTONUP:
		case SDL_KEYUP:
			std::cout << "start menu!" << std::endl;
			current_signal = GLBL::menuState;
			break;
		default:
			break;
		}
	}
}

void IntroState::update(GameEngine* game)
{
	switch (current_signal)
	{
	case(GLBL::none):
		GameState::update(game);
		break;
	case(GLBL::quit):
		game->exit();
		break;
	case(GLBL::menuState):
		game->PushState(current_signal);
		game->ChangeState(current_signal);
		break;
	}
	
}



bool IntroState::loadTextures()
{
	if (!textur_map->loadTexture("gfx/intro.png", "intro"))
	{
		return false;
	}
	textures_id.push_back("intro");

	if (!textur_map->loadTexture("gfx/lightning.png", "lightning"))
	{
		return false;
	}
	textures_id.push_back("lightning");

	return true;
}
