#include "pch.h"
#include "player.h"
#include "graphics.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
	const float RUN_SPEED = 0.4f;
	const float jumpHeight = 1.0f;
}

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "Sprites/swordCharacter.png", 0, 0, 48, 48, x, y, 100) {
	graphics.loadImage("Sprites/swordCharacter.png");

	this->setupAnimations();
	this->playAnimation("IdleRight");
	}

void Player::setupAnimations() {
	this->addAnimation(6, 0, 528, "WalkRight", 48, 48, Vector2(0, 0));
	this->addAnimation(6, 0, 480, "RunRight", 48, 48, Vector2(0, 0));
	this->addAnimation(4, 0, 336, "IdleRight", 48, 48, Vector2(0, 0));
	this->addAnimation(6, 0, 384, "Jump", 48, 48, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("WalkRight");
	this->_facing = RIGHT;
}
void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("WalkRight");
	this->_facing = LEFT;
}
void Player::runLeft() {
	this->_dx = -player_constants::RUN_SPEED;
	this->playAnimation("RunRight");
	this->_facing = LEFT;
}
void Player::runRight() {
	this->_dx = player_constants::RUN_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}
void Player::jump() {
	this->_dy = player_constants::jumpHeight;
	this->playAnimation("Jump", true);
}
void Player::stopMoving() {
	this->_dx = 0.0f;
	// when you add left do "this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");"
	this->playAnimation("IdleRight");
}




void Player::update(float elapsedTime) {
	//Move by dx
	this->_x += this->_dx *elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}