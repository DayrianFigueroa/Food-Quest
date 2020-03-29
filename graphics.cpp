#include "pch.h"
#include "SDL.h"
#include "graphics.h"
#include "SDL_image.h"
#include "globals.h"

/* Graphics class
	Holds all information dealing with graphics for the game.
*/

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Food Quest");
}
Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	/*
	std::string file;
	while (file != "exit") {
		std::getline(std::cin, file);
		this->_spriteSheets[file] = IMG_Load(file.c_str());
		if (this->_spriteSheets[filePath] == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n", file.c_str(), IMG_GetError());
		}
		else if (this->_spriteSheets[filePath] != NULL) {
			printf("\nERROR: IMAGE DID LOAD\n");
		}
	}
	*/
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	if (this->_spriteSheets[filePath] == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurfacer(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}