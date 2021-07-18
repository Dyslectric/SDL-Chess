#include "render.h"

void render(GameWindow window, GameState state)
{
	SDL_RenderClear(window.renderer);

	SDL_Rect destRect;
	if(true)
	{
		destRect = get_dest_rect(window, DEST_BOARD, NON);
		SDL_RenderCopy(window.renderer, window.textures[Board], NULL, &destRect);
	}

	SDL_RenderPresent(window.renderer);
}

// calculates height of window and resizes and re places board
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
			rect.h = width;
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
	return rect;
}