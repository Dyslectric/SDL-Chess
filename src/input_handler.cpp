#include "input_handler.h"

GameInput input_handler(SDL_Event event)
{
	GameInput input;
	input.type = NON;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			input.type = I_QUIT;
			return input;
		}
	}

	return input;
}