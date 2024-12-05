#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <SDL.h>
#include "baseScene.h"

class InputVars {
public:
	bool mouse_down = false;
};

class Input {
public:
	void handleInput(bool& running);
};

extern Input funcs;
extern InputVars vars;

#endif // INPUT_H
