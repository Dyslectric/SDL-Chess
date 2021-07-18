#ifndef __INPUT_HANDLER
#define __INPUT_HANLDER

#include <iostream>
#include <SDL2/SDL.h>

#include "structs.h"
#include "logic.h"

GameInput	input_handler(SDL_Event event);
int			get_tile(const int x, const int y);

#endif