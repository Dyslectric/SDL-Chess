#ifndef __RENDER
#define __RENDER

#include <iostream>
#include <SDL2/SDL.h>

#include "structs.h"

void render();
void draw_board();
void draw_legals_and_checks();
void draw_pieces();
void draw_held_piece();
SDL_Rect get_dest_rect(const int flag, const int tile);

#endif