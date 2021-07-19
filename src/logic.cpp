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
		state.legalsBoard[tile] = TilePrevious;
		get_legals(tile);
		state.board[tile] = NON;
	}

	else if(state.board[tile] == NON && state.heldPiece != NON)
	{
		reset_legals_board();
		state.board[tile] = state.heldPiece;
		get_checks();
		state.heldPiece = NON;
		return;
	}
}

void get_legals(const int tile)
{
	state.legalsBoard[tile] = TileRed;
	if(state.heldPiece == WhitePawn)
	{
		if(is_empty_tile(tile - 8))
		{
			state.legalsBoard[tile - 8] = TileGreen;

			if(tile < 56 && tile >= 48 && state.board[tile - 16] == NON)
			{
				state.legalsBoard[tile - 16] = TileGreen;
			}
		}
		if
		(	
			!is_empty_tile(tile - 7) &&
			is_black_piece(tile - 7) &&
			!is_rightmost_piece(tile)
		)
		{
			state.legalsBoard[tile - 7] = TileGreen;
		}
		if
		(
			!is_empty_tile(tile - 9) &&
			is_black_piece(tile - 9) &&
			!is_leftmost_piece(tile)
		)
		{
			state.legalsBoard[tile - 9] = TileGreen;
		}
	}

	if(state.heldPiece == BlackPawn)
	{
		if(is_empty_tile(tile + 8))
		{
			state.legalsBoard[tile + 8] = TileGreen;

			if(tile < 16 && tile >= 8 && state.board[tile + 16] == NON)
			{
				state.legalsBoard[tile + 16] = TileGreen;
			}
		}
		if
		(
			!is_empty_tile(tile + 7) &&
			is_white_piece(tile + 7) &&
			!is_leftmost_piece(tile)
		)
		{
			state.legalsBoard[tile + 7] = TileGreen;
		}
		if
		(
			!is_empty_tile(tile + 9) &&
			is_white_piece(tile + 9) &&
			!is_rightmost_piece(tile)
		)
		{
			state.legalsBoard[tile + 9] = TileGreen;
		}
	}

	if(state.heldPiece == WhiteKnight)
	{

	}

	if(state.heldPiece == BlackKnight)
	{

	}

	if(state.heldPiece == WhiteBishop)
	{

	}

	if(state.heldPiece == BlackBishop)
	{

	}

	if(state.heldPiece == WhiteRook)
	{

	}

	if(state.heldPiece == BlackRook)
	{

	}

	if(state.heldPiece == WhiteQueen)
	{

	}

	if(state.heldPiece == BlackQueen)
	{

	}

	if(state.heldPiece == WhiteKing)
	{

	}

	if(state.heldPiece == BlackKing)
	{

	}
}

void get_checks()
{

}

void reset_legals_board()
{
	for(int i = 0; i < 64; i++)
	{
		state.legalsBoard[i] = -1;
	}
}

int is_empty_tile(const int tile)
{
	return state.board[tile] == NON;
}

int is_white_piece(const int tile)
{
	return (state.board[tile] / 6) < 1;
}

int is_black_piece(const int tile)
{
	return (state.board[tile] / 6) > 0;
}

int is_leftmost_piece(const int tile)
{
	return (tile % 8) == 0;
}

int is_rightmost_piece(const int tile)
{
	return (tile % 8) == 7;
}