#include "input_handler.h"

GameInput input_handler(SDL_Event event)
{
	GameInput input;
	input.type = NON;

	while(SDL_PollEvent(&event))
	{
		if
		(
			event.type == SDL_QUIT
		)
		{
			input.type = I_QUIT;
			return input;
		}

		if
		(
			event.type == SDL_MOUSEBUTTONDOWN &&
			event.button.button == SDL_BUTTON_LEFT
		)
		{
			input.type = I_TILE;
			input.tile = get_tile(event.button.x, event.button.y);
			return input;
		}
	}
	return input;
}

//	good luck getting these algorithms, bucko, they took hours
int get_tile(const int x, const int y)
{
	int width;
	int height;
	SDL_GetWindowSize(window.window, &width, &height);

	if(width == height)
	{
		return ((x / (width / 8)) + (y / (height / 8) * 8));
	}

	if(width > height)
	{
		if(x < ((width - height) / 2) || x > ((width - height) / 2) + height)
		{
			return NON;
		}
		return (((x - ((width - height) / 2)) / (height / 8)) + (y / (height / 8) * 8));
	}

	if(width < height)
	{
		if(y < ((height - width) / 2) || y > ((height - width) / 2) + width)
		{
			return NON;
		}
		return ((x / (width / 8)) + (((y - ((height - width) / 2))) / (width / 8) * 8));
	}

	return NON;
}