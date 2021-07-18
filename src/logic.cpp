#include "logic.h"
#include "globals.h"

void logic(GameInput input)
{
	if(input.type == NON)
	{
		return;
	}

	if(input.type == I_QUIT)
	{
		state.quit = true;
		return;
	}

	if(input.type == I_TILE)
	{
		if(input.tile == NON)
			return;
		game(input.tile);
	}
}

void game(const int tile)
{
	if(state.board[tile] != NON && state.heldPiece == NON)
	{
		state.heldPiece = state.board[tile];
		state.board[tile] = NON;
		return;
	}

	if(state.board[tile] == NON && state.heldPiece != NON)
	{
		state.board[tile] = state.heldPiece;
		state.heldPiece = NON;
		return;
	}
}