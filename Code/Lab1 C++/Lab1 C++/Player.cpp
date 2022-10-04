#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer) {
	renderer = sdlRenderer;
}

void Player::init() {
	SDL_Surface* image = IMG_Load("assets/chibiCarlo.png");
	if (image == nullptr) {
		std::cout << "Couldn't load image" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Player::render() {
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}