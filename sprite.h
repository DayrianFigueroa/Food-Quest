#ifndef SPRITE_H
#define SPRITE_H

#include "SDL.h"
#include <string>
class Graphics;

/* Sprite class
	Holds all information for individual sprites
*/

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filepath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
	void changeScale(float scale);
	float getScale();
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	float spriteScale;
	float _x, _y;
private:
	
};

#endif