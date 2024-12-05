#ifndef SM_H
#define SM_H

#include <vector>

// this helps prevent circular dependancy errors
class Scene;

class SceneM {
public:
    Scene* currentscene;

    SceneM() : currentscene(nullptr) {}
    ~SceneM();

    void changeScene(std::vector<Scene*> scenes, int new_scene);
    void handleEvents(bool& running);
    void render();
};

#endif
