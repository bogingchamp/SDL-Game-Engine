#include "sceneManager.h"
#include "baseScene.h" // Include full definition of Scene to prevent use of undefined type errors
#include <iostream>

SceneM::~SceneM()
{
    if (!currentscene) {
        return;
    }
}

void SceneM::changeScene(std::vector<Scene*> scenes, int new_scene) {
    std::cout << "changing scene\n";

    currentscene = scenes[new_scene];

    if (!currentscene) {
        std::cout << "currentscene was freed early \n";
        return;
    }

    // Skip deletion and onready if switching to the same scene
    if (currentscene == scenes[new_scene]) {
        std::cout << "Attempting to switch to the same scene. Skipping deletion and running onready procedures.\n";
        currentscene->onreadywithparam(this, scenes);
        return;
    }

    // Switch to the new scene before deleting the current scene
    Scene* oldScene = currentscene;
    currentscene = scenes[new_scene];

    // Run onreadywithparam on the new scene
    if (currentscene) {
        currentscene->onreadywithparam(this, scenes);
    }

    // Delete the old scene after switching to the new one
    delete oldScene;
}

void SceneM::handleEvents(bool& running)
{
    if (currentscene) {
        currentscene->handleEvents(running);
    }
}

void SceneM::render()
{
    if (currentscene) {
        currentscene->render();
    }
}
