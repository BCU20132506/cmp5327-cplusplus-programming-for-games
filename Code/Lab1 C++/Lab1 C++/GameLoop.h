#pragma once

#include <SDL.h>
#include <iostream>
#include "Player.h"
#define SDL_MAIN_HANDLED

const int screenWidth = 800;
const int screenHeight = 600;


class GameLoop
{
public:
	int init();

	void update();
	void render();

	bool keepAlive();

	void clean();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	Player* player = nullptr;
};

