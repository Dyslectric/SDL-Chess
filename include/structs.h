#ifndef __STRUCTURES
#define __STRUCTURES

#include <SDL2/SDL.h>

#include "definitions.h"

struct GameWindow
{
    int xpos;
    int ypos;
    int width;
    int height;

    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_Texture*    textures[TextureCount];

    SDL_Rect rectSources[12];
};

struct GameState
{
    int quit;
    int turn;
    int board[64];
    int legalsBoard[64];
    int heldPiece;
    int promotion;
};

struct GameInput
{
    int type;
    int tile;
};

#endif