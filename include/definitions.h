#ifndef __DEFINITIONS
#define __DEFINITIONS

//  Window Title
#define Name "SDL-Chess"

//  frame time (60fps by default)
#define Delta 1.0 / 144.0

//  General null like thing for this program is -1
#define NON -1

#define true 1
#define false 0

//  Names for texture indicies
enum texture_indicies
{
    Board, Pieces, TileGreen, TileRed
};

//  caching every texture for this game at once
//  it's kind of pointless not to for chess
#define TextureCount 4

//  Flags for get_dest_rect
enum dest_flags
{
    DEST_BOARD, DEST_TILE, DEST_HELD
};

// turn values for game logic
#define Turn_White  0
#define Turn_Black  1

//  this is used to index pieces on the board and
//  the rectangles used by sdl for rendering
enum piece
{
    WhitePawn=0, WhiteKnight, WhiteBishop, WhiteRook, WhiteQueen, WhiteKing,
    BlackPawn, BlackKnight, BlackBishop, BlackRook, BlackQueen, BlackKing
};

//  input types for input_handler to return into the logic function
enum input_types
{
    I_QUIT, I_TILE
};

#endif