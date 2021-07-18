#include "render.h"

void render(GameWindow window, GameState state)
{
	SDL_RenderClear(window.renderer);

	if(true)
	{
		draw_board(window, state);
	}

	if(true)
	{
		draw_hints(window, state);
	}

	if(true)
	{
		draw_pieces(window, state);
	}

	SDL_RenderPresent(window.renderer);
}

//	draws the chess board
void draw_board(GameWindow window, GameState state)
{
	SDL_Rect destRect;
	destRect = get_dest_rect(window, DEST_BOARD, NON);
	SDL_RenderCopy(window.renderer, window.textures[Board], NULL, &destRect);
}

void draw_hints(GameWindow window, GameState state)
{
	SDL_Rect destRect;

	for(int i = 0; i < 64; i++)
	{
		if(state.hintBoard[i] == NON)
		{
			continue;
		}

		else
		{
			destRect = get_dest_rect(window, DEST_TILE, i);
			if(state.hintBoard[i] == TileGreen)
			{
				SDL_RenderCopy(	window.renderer, window.textures[TileGreen],
								NULL, &destRect);
			}

			if(state.hintBoard[i] == TileRed)
			{
				SDL_RenderCopy(	window.renderer, window.textures[TileRed],
								NULL, &destRect);
			}
		}
	}
}

void draw_pieces(GameWindow window, GameState state)
{
	SDL_Rect destRect;

	for(int i = 0; i < 64; i++)
	{
		if(state.board[i] == NON)
		{
			continue;
		}

		else
		{
			destRect = get_dest_rect(window, DEST_TILE, i);
			SDL_RenderCopy(	window.renderer, window.textures[Pieces],
							&window.rectSources[state.board[i]], &destRect);
		}
	}
}

// calculates width/height of window and returns SDL_Rect of where to put a texture
SDL_Rect get_dest_rect(const GameWindow window, const int flag, const int tile)
{
	SDL_Rect rect;

	int width;
	int height;

	SDL_GetWindowSize(window.window, &width, &height);

	if(flag == DEST_BOARD)
	{
		if(width == height)
		{
			rect.x = 0;
			rect.y = 0;
			rect.w = width;
			rect.h = height;
			return rect;
		}

		if(width > height)
		{
			rect.x = (width - height) / 2;
			rect.y = 0;
			rect.w = height;
			rect.h = height;
			return rect;
		}

		if(width < height)
		{
			rect.x = 0;
			rect.y = (height - width) / 2;
			rect.w = width;
			rect.h = width;
			return rect;
		}
	}

	if(flag == DEST_TILE)
	{
		rect.x = width / 8 * (tile % 8);
		rect.y = height / 8 * (tile / 8);
		rect.w = width / 8;
		rect.h = height / 8;

		if(width == height)
		{
			return rect;
		}

		if(width > height)
		{
			rect.x = height / 8 * (tile % 8) + (width - height) / 2;
			rect.w = rect.h;
			return rect;
		}

		if(width < height)
		{
			rect.y = width / 8 * (tile / 8) + (height - width) / 2;
			rect.h = rect.w;
			return rect;
		}
	}

	return rect;
}