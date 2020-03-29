#include "pch.h"
#include "SDL.h"
#include "game.h"
#include "graphics.h"
#include "input.h"
#include <algorithm>
#include "globals.h"
#include <iostream>

/* Game class
	Holds all the information for the main game's loop
*/

namespace{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}
Game::~Game() {

}	
void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	this->_player = Player(graphics, globals::SCREEN_WIDTH/2, globals::SCREEN_HEIGHT/2);


	
	// ms after library was started *important to start out of loop*
	int LAST_UPDATE_TIME = SDL_GetTicks();

	// Start game loop
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		//if (input.wasKeyPressed(SDL_SCANCODE_SPACE) == true) {
		//	this->_player.jump();
		//}
		else if (input.isKeyHeld(SDL_SCANCODE_LSHIFT) == true) {
			if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
				this->_player.runLeft();
			}
			else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
				this->_player.runRight();
			}
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}
		if (!(input.isKeyHeld(SDL_SCANCODE_LEFT)) && !(input.isKeyHeld(SDL_SCANCODE_RIGHT)) /*&& !(input.isKeyHeld(SDL_SCANCODE_SPACE))*/) {
			this->_player.stopMoving();
		}
		

		// Goal = to get elapsed time ms
		// Goal is also to get a person with a slower computer and lower fps to move same distance in same time as someone with a better computer with higher fps
		int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}
void Game::draw(Graphics &graphics) {
	graphics.clear();

	this->_player.draw(graphics);
	graphics.flip();
}
void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}