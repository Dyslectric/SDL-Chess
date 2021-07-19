#include <iostream>
#include <SDL2/SDL.h>

#include "definitions.h"
#include "structs.h"
#include "globals.h"

void	logic(GameInput input);
void	game(const int tile);
void	get_legals(const int tile);
void	get_checks();
void	reset_legals_board();

int		is_empty_tile(const int tile);
int		is_white_piece(const int tile);
int		is_black_piece(const int tile);
int		is_leftmost_piece(const int tile);
int		is_rightmost_piece(const int tile);