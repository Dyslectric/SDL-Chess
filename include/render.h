#ifndef __RENDER
#define __RENDER

#include <iostream>
#include <SDL2/SDL.h>

#include "structs.h"

void render();
void draw_board();
void draw_hints();
void draw_pieces();
SDL_Rect get_dest_rect(const int flag, const int tile);

#endif