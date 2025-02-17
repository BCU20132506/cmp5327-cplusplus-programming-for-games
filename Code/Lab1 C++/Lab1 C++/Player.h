#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	//Player();

	Player(SDL_Renderer* sdlRenderer);

	void init();
	void render();
	void update();
	void clean();

private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

