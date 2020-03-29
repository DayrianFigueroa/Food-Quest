#ifndef GAME_H
#define Game_H

#include "player.h"

/* Game class
	Holds all the information for the main game's loop
*/

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	Player _player;
};

#endif
