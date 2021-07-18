#ifndef __INIT_FUNCTIONS
#define __INIT_FUNCTIONS

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"

int init();

int     init_modules();
int     init_window();
int     init_textures();
int     init_rects();
void    init_state();

#endif