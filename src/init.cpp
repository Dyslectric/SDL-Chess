#include "init.h"
#include "globals.h"

int init()
{
    if (init_modules())
    {
        std::cout << "Module initialization failed." << std::endl;
        return 1;
    }

    if (init_window())
    {
        std::cout << "Window initialization failed." << std::endl;
        return 1;
    }

    if (init_textures())
    {
        std::cout << "Texture loading failed." << std::endl;
        return 1;
    }

    if (init_rects())
    {
        std::cout << "SDL_Rect creation failed." << std::endl;
        return 1;
    }

    init_state();
    return 0;
}

int init_modules()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout <<    "SDL_INIT_VIDEO has failed\n" <<
                        "Error code: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (SDL_Init(IMG_INIT_PNG))
    {
        std::cout <<    "IMG_INIT_PNG has failed\n" <<
                        "Error code: " << SDL_GetError() << std::endl;
        return 1;
    }

    return 0;
}

int init_window()
{
    window.xpos = SDL_WINDOWPOS_UNDEFINED;
    window.ypos = SDL_WINDOWPOS_UNDEFINED;

    window.width = 800;
    window.height = 800;

    window.window = SDL_CreateWindow(   Name,
                                        window.xpos, window.ypos,
                                        window.width, window.height,
                                        SDL_WINDOW_SHOWN);

    if(window.window == NULL)
        std::cout <<    "SDL_CreateWindow failed.\n"
                        "Error code: " << SDL_GetError() << std::endl;

    window.renderer = SDL_CreateRenderer(   window.window, -1,
                                            SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);

    if(window.renderer == NULL)
        std::cout <<    "SDL_CreateRenderer failed.\n"
                        "Error code: " << SDL_GetError() << std::endl;

    SDL_SetWindowResizable(window.window, SDL_TRUE);

    return 0;
}

int init_textures()
{
    window.textures[Board]          = IMG_LoadTexture(window.renderer, "assets/board.png");
    window.textures[Pieces]         = IMG_LoadTexture(window.renderer, "assets/pieces.png");
    window.textures[TileGreen]      = IMG_LoadTexture(window.renderer, "assets/tile_green.png");
    window.textures[TileRed]        = IMG_LoadTexture(window.renderer, "assets/tile_red.png");

    return 0;
}

// this function divides the pieces png into 12 sdl rects for rendering
int init_rects()
{
    int pawn    = 2560 / 6 * 5;
    int knight  = 2560 / 6 * 3;
    int bishop  = 2560 / 6 * 2;
    int rook    = 2560 / 6 * 4;
    int queen   = 2560 / 6 * 1;
    int king    = 0;

    int white   = 0;
    int black   = 854 / 2;

    int width   = 2560 / 6;
    int height  = 854 / 2;

    window.rectSources[WhitePawn].x     = pawn;
    window.rectSources[BlackPawn].x     = pawn;
    window.rectSources[WhiteKnight].x   = knight;
    window.rectSources[BlackKnight].x   = knight;
    window.rectSources[WhiteBishop].x   = bishop;
    window.rectSources[BlackBishop].x   = bishop;
    window.rectSources[WhiteRook].x     = rook;
    window.rectSources[BlackRook].x     = rook;
    window.rectSources[WhiteQueen].x    = queen;
    window.rectSources[BlackQueen].x    = queen;
    window.rectSources[WhiteKing].x     = king;
    window.rectSources[BlackKing].x     = king;

    window.rectSources[WhitePawn].y     = white;
    window.rectSources[WhiteKnight].y   = white;
    window.rectSources[WhiteBishop].y   = white;
    window.rectSources[WhiteRook].y     = white;
    window.rectSources[WhiteQueen].y    = white;
    window.rectSources[WhiteKing].y     = white;
    window.rectSources[BlackPawn].y     = black;
    window.rectSources[BlackKnight].y   = black;
    window.rectSources[BlackBishop].y   = black;
    window.rectSources[BlackRook].y     = black;
    window.rectSources[BlackQueen].y    = black;
    window.rectSources[BlackKing].y     = black;

    for(int i = 0; i < 12; i++)
    {
        window.rectSources[i].w         = width;
        window.rectSources[i].h         = height;
    }

    return 0;
}

void init_state()
{
    int startBoard[] =
    {
        6,  6,  6,  6,  6,  6,  6,  6,
        9,  7,  8,  10, 11, 8,  7,  9,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        3,  1,  2,  4,  5,  2,  1,  3,
        0,  0,  0,  0,  0,  0,  0,  0
    };

    int startHintBoard[] =
    {
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1
    };

    state.quit = false;
    state.turn = Turn_White;
    state.heldPiece = NON;

    for(int i = 0; i < 64; i++)
    {
        state.board[i] = startBoard[i];
        state.hintBoard[i] = startHintBoard[i];
    }
}
