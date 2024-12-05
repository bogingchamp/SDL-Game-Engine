SDL Game Engine
Welcome to the SDL Game Engine! This engine provides a robust set of systems to kickstart your game development journey with SDL. It includes essential features like:

Scene System: Manage and transition between different game scenes effortlessly.
Interactive and Static UI: Create intuitive and engaging user interfaces.
Signal System: Decouple event handling with a powerful signal-slot mechanism.
With this engine, setting up your project is incredibly straightforward.

📦 Setting Up the Engine
Create the Project Structure:

Create a folder called engine and place all the engine's source code there.
Create another folder called scenes and add a header file named sceneUtils.h in it.
Setup sceneUtils.h: Paste the following code into sceneUtils.h:

```
// Contains all important headers to build a scene
#ifndef SU_H
#define SU_H

#include "../UI.h"
#include "../baseScene.h"
#include "../input.h"
#include "../Signals.h"
#include "../sceneManager.h"

class Utils {
public:
    Signals* signal;

    Utils() {
        if (!signal) {
            signal = new Signals;
        }
    }
};

#endif
```

All Set! You’re now ready to start creating your game with the engine.

🛠️ Examples
Below are examples of how you can use this engine to build a main menu for your game.

menu.h:
```
// SCENE INDEX 0

#ifndef MM_H
#define MM_H

#include "sceneUtils.h"

class MainMenu : public Scene {
public:
    Utils* utils;

    MainMenu(SDL_Renderer* renderer, TTF_Font* font, SceneM* sm, std::vector<Scene*> scenes)
        : Scene(renderer, font), utils(new Utils()) {

        if (!utils) {
            utils = new Utils(); // Or initialize through dependency injection.
        }

        addButton(new Button(300, 200, 200, 50, "Start Game", renderer, font, 30, 0, SDL_Color{ 0, 255, 0, 255 }));
        addButton(new Button(300, 300, 200, 50, "Exit", renderer, font, 30, 1));
    }

    ~MainMenu() { sceneDeletionProcedures(); std::cout << "MainMenu destroyed\n"; }

    void onreadywithparam(SceneM* sm, std::vector<Scene*> scenes) override;
    void onready() override;
    void handleEvents(bool& running) override;
    void getButtonFunc(int id) override;
    void setBG() override;

    void sceneDeletionProcedures() override;

public:
    static void start_game(SceneM* sm, std::vector<Scene*> scenes);

private:
    bool should_quit = false;
};

#endif // !MM_H
```

menu.cpp:
The menu.cpp file handles the functionality of the menu buttons and background. For a detailed implementation, check the full source code in this repository.

Main File Example:
Set up your main file to integrate the engine and handle game logic:

```
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "allScenes.h"
#include "input.h"
#include "sceneManager.h"

#undef main

std::vector<Scene*> scenes;

void addScenes(SDL_Renderer* renderer, TTF_Font* font, std::vector<Scene*>& scenes, SceneM* sm) 
{
    scenes.push_back(new MainMenu(renderer, font, sm, scenes));
    scenes.push_back(new MainGame(renderer, font, sm, scenes));
}

int main(int argc, char* argv[]) {
    // Initialize SDL, create the window, renderer, and load assets
    // See the full code above for implementation details

    bool running = true;
    while (running) {
        // Main game loop
    }

    // Cleanup code
    return 0;
}
```

🤔 Why Use This Engine?
Rapid Development: Spend more time crafting your game and less time building boilerplate code. The engine provides a pre-configured foundation to jump straight into development.

Ease of Use: Intuitive structure and clear API make it easy for beginners and seasoned developers alike.

Highly Modular: The engine's systems are designed for flexibility, enabling you to adapt and extend them for your unique requirements.

Focus on Quality: Built with efficiency and maintainability in mind, the engine ensures your project remains clean and organized.

Comprehensive Features: From UI to scene management and event handling, this engine covers all the bases for a 2D game.

🚀 Getting Started
Clone this repository.
Follow the setup steps above.
Start adding scenes and implementing game logic.
With this engine, you'll have the tools and flexibility to create incredible games in SDL. Happy coding! 🎮
