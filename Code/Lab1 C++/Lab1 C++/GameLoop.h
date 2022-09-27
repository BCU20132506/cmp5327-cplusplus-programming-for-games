#pragma once

#include <SDL.h>
#include <iostream>
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

};

