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
			//input.tile = get_tile(event.button.x, event.button.y);
			return input;
		}
	}
	return input;
}

int get_tile(const int x, const int y)
{

}