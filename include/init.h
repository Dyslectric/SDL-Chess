#ifndef __INIT_FUNCTIONS
#define __INIT_FUNCTIONS

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "structs.h"

namespace init
{
    int         modules();
    GameWindow  window();
    void        rects(SDL_Rect* rect_array);
    void        textures(GameWindow &window);
    GameState   state();
}

#endif