#ifndef GRAPHICS_H
#define GRAPHICS_H

/* Graphics class
	Holds all information dealing with graphics for the game
*/

#include <map>
#include <string>

// Help to not use include too many times and reduces duplication which removes future errors.
struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

	/* SDL_Surface* loadImage
		loads an image into the _spriteSheets map if it doesnt already exist
		as a result, each image will only ever be loaded once
		returns the image from the map regardless of whether or not is was just loaded
	*/
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
		Draws a texture to a certian part of the screen
	*/
	void blitSurfacer(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
		Renders everything into the screen
	*/
	void flip();

	/* void clear
		Clears the screen
	*/
	void clear();

	/* SDL_Renderer* getRenderer
		Returns the renderer
	*/
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif