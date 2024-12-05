#include "button.h"
#include <iostream>

Button::Button(int x, int y, int w, int h, const std::string& label, SDL_Renderer* renderer,
    TTF_Font* font, int buttonFontSize, int id, std::optional<SDL_Color> color)
    : renderer(renderer), id(id), text(label), color(color.value_or(SDL_Color{ 128, 128, 128, 255 })), rect({ x, y, w, h }) {

    buttonFont = TTF_OpenFont("Assets/font/Sans.ttf", buttonFontSize); 

    if (!buttonFont) {
        std::cerr << "Failed to load button font: " << TTF_GetError() << std::endl;
    }

    loadTexture();
}

Button::~Button() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Button::render() {
    // Draw the button as a filled rectangle with the specified color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);

    // Only render the text if the texture has been successfully loaded
    if (texture) {
        SDL_Rect dstRect = { rect.x + (rect.w - textureWidth) / 2, rect.y + (rect.h - textureHeight) / 2, textureWidth, textureHeight };
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    }
    else {
        std::cerr << "Button texture is not loaded!" << std::endl;
    }
}

bool Button::isClicked(int mouseX, int mouseY) {
    return (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
        mouseY >= rect.y && mouseY <= rect.y + rect.h);
}

void Button::loadTexture() {
    SDL_Color textColor = { 255, 255, 255, 255 };  // White text color

    // Use the button's specific font for rendering button text
    SDL_Surface* surface = TTF_RenderText_Blended(buttonFont, text.c_str(), textColor);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);  // Free the surface after texture creation

        if (texture) {
            SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
        }
        else {
            std::cerr << "Failed to create texture from surface! SDL Error: " << SDL_GetError() << std::endl;
        }
    }
    else {
        std::cerr << "Unable to create surface for button text! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
}

