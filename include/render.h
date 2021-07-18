#ifndef __RENDER
#define __RENDER

#include <iostream>
#include <SDL2/SDL.h>

#include "structs.h"

void render(GameWindow window, GameState state);
SDL_Rect get_dest_rect(const GameWindow window, const int flag, const int tile);

#endif