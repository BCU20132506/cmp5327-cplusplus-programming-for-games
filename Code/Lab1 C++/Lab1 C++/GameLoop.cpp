#include "GameLoop.h"

SDL_Window* window;
SDL_Surface* screenSurface;

int GameLoop::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialise SDL2" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	window = SDL_CreateWindow(
		"Game Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		std::cout << "Could not initialise window" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	screenSurface = SDL_GetWindowSurface(window);

	player = new Player(renderer);
	player->init();
	return 0;
}

bool GameLoop::keepAlive() {
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput)) {
		if (userInput.type == SDL_QUIT)
		{
			return false;
		}

		if (userInput.type == SDL_KEYDOWN) {
			switch (userInput.key.keysym.scancode) {
			case SDL_SCANCODE_F:
				break;
			default:
				break;
			}
		}
	}

	return true;
}

void GameLoop::update() {

}

void GameLoop::render() {

	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void GameLoop::clean() {

	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();

}