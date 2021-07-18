#include "init.h"

int init::modules()
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

GameWindow init::window()
{
    GameWindow window;

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

    return window;
}

// this function divides the pieces png into 12 sdl rects for rendering
void init::rects(SDL_Rect* rectArray)
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

    rectArray[WhitePawn].x     = pawn;
    rectArray[BlackPawn].x     = pawn;
    rectArray[WhiteKnight].x   = knight;
    rectArray[BlackKnight].x   = knight;
    rectArray[WhiteBishop].x   = bishop;
    rectArray[BlackBishop].x   = bishop;
    rectArray[WhiteRook].x     = rook;
    rectArray[BlackRook].x     = rook;
    rectArray[WhiteQueen].x    = queen;
    rectArray[BlackQueen].x    = queen;
    rectArray[WhiteKing].x     = king;
    rectArray[BlackKing].x     = king;

    rectArray[WhitePawn].y     = white;
    rectArray[WhiteKnight].y   = white;
    rectArray[WhiteBishop].y   = white;
    rectArray[WhiteRook].y     = white;
    rectArray[WhiteQueen].y    = white;
    rectArray[WhiteKing].y     = white;
    rectArray[BlackPawn].y     = black;
    rectArray[BlackKnight].y   = black;
    rectArray[BlackBishop].y   = black;
    rectArray[BlackRook].y     = black;
    rectArray[BlackQueen].y    = black;
    rectArray[BlackKing].y     = black;

    for(int i = 0; i < 12; i++)
    {
        rectArray[i].w         = width;
        rectArray[i].h         = height;
    }
}

void init::textures(GameWindow &window)
{
    window.textures[Board]          = IMG_LoadTexture(window.renderer, "assets/board.png");
    window.textures[Pieces]         = IMG_LoadTexture(window.renderer, "assets/pieces.png");
    window.textures[TileGreen]      = IMG_LoadTexture(window.renderer, "assets/tile_green.png");
    window.textures[TileRed]        = IMG_LoadTexture(window.renderer, "assets/tile_red.png");
}

GameState init::state()
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

    GameState state;

    state.quit = false;
    state.turn = Turn_White;
    state.heldPiece = NON;

    for(int i = 0; i < 64; i++)
    {
        state.board[i] = startBoard[i];
        state.hintBoard[i] = startHintBoard[i];
    }

    return state;
}
