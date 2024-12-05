#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "button.h"
#include "UI.h"
#include <SDL.h>

// once again, this helps prevent circular dependency errors
class SceneM;

class Scene {
protected:
    SDL_Renderer* renderer;
    TTF_Font* font;
    std::vector<Button*> buttons;
    std::vector<TextLabel*> labels;
    std::vector<Image*> images;

public:
    Scene(SDL_Renderer* renderer, TTF_Font* font);
    virtual ~Scene();

    void addButton(Button* button);
    void addText(TextLabel* label);
    void addImage(Image* image);

    virtual void render();
    virtual void getButtonFunc(int id) = 0; // Pure virtual function for handling button clicks

    virtual void handleEvents(bool& running) = 0;

    virtual void setBG() = 0;

    virtual void onready() = 0; // runs when scene is loaded
    virtual void onreadywithparam(SceneM* sm, std::vector<Scene*> scenes) = 0;

    virtual void sceneDeletionProcedures() = 0;
};

#endif // SCENE_H
