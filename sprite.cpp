#include "pch.h"
#include "sprite.h"
#include "graphics.h"
#include "globals.h"

Sprite::Sprite() {
	this->spriteScale = 4.0f;
}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX),
	_y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
	this->spriteScale = 4.0f;
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w*this->spriteScale, this->_sourceRect.h*this->spriteScale };
	graphics.blitSurfacer(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::changeScale(float scale) {
	this->spriteScale = scale;
}

float Sprite::getScale() {
	return this->spriteScale;
}

void Sprite::update() {}