#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <optional>

class Button {
public:
    // Constructor with a new 'buttonFont' to separate button text rendering from label text
    Button(int x, int y, int w, int h, const std::string& label, SDL_Renderer* renderer,
        TTF_Font* font, int buttonFontSize, int id, std::optional<SDL_Color> color = std::nullopt);
    ~Button();

    void render();
    bool isClicked(int mouseX, int mouseY);

    int id;

private:
    SDL_Rect rect;
    SDL_Color color;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    TTF_Font* font;      // not sure if this is useful or not
    TTF_Font* buttonFont; 
    std::string text;

    int textureWidth, textureHeight;

    void loadTexture();
};

#endif // BUTTON_H
