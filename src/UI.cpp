#include "UI.h"

#pragma region text_box_implementation
// Constructor that initializes the label with text, position, font, color, and font size
TextLabel::TextLabel(const std::string& text, int x, int y, SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int fontSize)
    : text(text), renderer(renderer), font(font), texture(nullptr), color(color) {
    position.x = x;
    position.y = y;

    TTF_SetFontSize(font, fontSize);

    updateTexture();  // Initialize the texture with the provided text
}

// Destructor to clean up resources
TextLabel::~TextLabel() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    if (font) {
        TTF_CloseFont(font);  // Close font to free resources
    }
}

// Render the label on the screen
void TextLabel::render() {
    if (texture) {
        SDL_RenderCopy(renderer, texture, nullptr, &position);
    }
}

// Set the text for the label and update the texture
void TextLabel::setText(const std::string& newText) {
    text = newText;
    updateTexture();  // Re-render the label with the new text
}

// Set the position of the label
void TextLabel::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

// Get the current text of the label
const std::string& TextLabel::getText() const {
    return text;
}

// Get the current position of the label
SDL_Rect TextLabel::getPosition() const {
    return position;
}

// Helper function to update the texture when the text changes
void TextLabel::updateTexture() {
    // Free the old texture if it exists
    if (texture) {
        SDL_DestroyTexture(texture);
    }

    // Render the new text as a surface
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface) {
        // Create the texture from the surface
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        position.w = surface->w; // Set the width of the text label
        position.h = surface->h; // Set the height of the text label
        SDL_FreeSurface(surface); // Free the surface as it is no longer needed
    }
}
#pragma endregion

#pragma region image_implementation

Image::Image(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer)
    : texture(texture), renderer(renderer), position{ x, y, width, height }
{
    if (!texture) {
        std::cerr << "Warning: Texture is null, image may not render correctly.\n";
    }
}

void Image::render() const
{
    if (texture) {
        SDL_RenderCopy(renderer, texture, nullptr, &position);
    }
    else {
        std::cerr << "Cannot render: Texture is null.\n";
    }
}

void Image::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void Image::setSize(int width, int height)
{
    position.w = width;
    position.h = height;
}

SDL_Rect Image::getPosition() const
{
    return position;
}

#pragma endregion
