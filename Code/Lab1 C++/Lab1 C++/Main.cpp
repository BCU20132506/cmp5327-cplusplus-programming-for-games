#define SDL_MAIN_HANDLED
#include <iostream>
#include <string>
#include <SDL.h>

int main() {

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "could not initialise SDL2" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		std::cout << "could not initialise window" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 144, 238, 144));
	SDL_UpdateWindowSurface(window);
	
	bool quitting = false;
	while (!quitting) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.scancode) {
				case SDL_SCANCODE_Q:
					quitting = true;
						break;
				}
			}
		}
	}

		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}