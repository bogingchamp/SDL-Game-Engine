#include "input.h"

InputVars vars;
Input funcs;

void Input::handleInput(bool& isRunning)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            vars.mouse_down = true;
        }
        else {
            vars.mouse_down = false;
        }
    }
}
