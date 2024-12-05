#include "baseScene.h"

Scene::Scene(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font) {}

Scene::~Scene() {
    for (Button* button : buttons) {
        delete button;
    }
    for (TextLabel* label : labels) {
        delete label;
    }
    for (Image* image : images) {
        delete image;
    }
}

void Scene::addButton(Button* button) 
{
    buttons.push_back(button);
}

void Scene::addText(TextLabel* label)
{
    labels.push_back(label);
}

void Scene::addImage(Image* image) 
{
    images.push_back(image);
}

void Scene::render() {
    for (Button* button : buttons) {
        button->render();
    }
    for (TextLabel* lable : labels) {
        lable->render();
    }
    for (Image* image : images) {
        image->render();
    }
}
