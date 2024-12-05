/*
This script and the C++ file are for UI elements
*/

#ifndef UI_H
#define UI_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class TextLabel {
public:
	TextLabel(const std::string& text, int x, int y, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int textSize);
	~TextLabel();

	void render();

	void setText(const std::string& text);
	void setPosition(int x, int y);
	const std::string& getText() const;
	SDL_Rect getPosition() const;

private:
	SDL_Texture* texture;  // The texture of the label's text
	SDL_Renderer* renderer; // SDL renderer to draw the texture
	TTF_Font* font;         // Font used to render the text
	std::string text;       // The actual text content
	SDL_Rect position;      // Position of the text on the screen
	SDL_Color color;

	void updateTexture();
};

class Image {
public:
	Image(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer);
	~Image() {}

	void render() const;

	void setPosition(int x, int y);
	void setSize(int width, int height);
	SDL_Rect getPosition() const;

private:
	SDL_Texture* texture;  // The texture of the image
	SDL_Renderer* renderer; // SDL renderer to draw the texture
	SDL_Rect position;      // Position and size of the image on the screen
};


#endif // !UI_H
