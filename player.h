#ifndef PLAYER_H
#define PLAYER_H
#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float updateTime);

	/* void moveLeft
		Moves player left by -_dx
	*/
	void moveLeft();

	/* void moveRight
		Moves player right by _dx
	*/
	void moveRight();

	void runRight();
	void runLeft();
	void jump();

	/* void stopMoving
		Stops moving player
	*/
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx, _dy;
	Direction _facing;
};

#endif