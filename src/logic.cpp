#include "logic.h"

void logic(GameInput input, GameState &state)
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
		//game(input.tile, state);
	}
}

//void game(int tile, GameState &state)
//{

//}