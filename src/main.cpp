#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"
#include "structs.h"
#include "tools.h"
#include "init.h"
#include "render.h"
#include "logic.h"
#include "input_handler.h"

int main(int argc, char** argv)
{
    if(init::modules())
        return 5;       //  returns 5 if module initialization fails

    GameWindow window = init::window();
    init::textures(window);
    GameState state = init::state();

    // initializaes the rects used to index the location of the 
    // piece textures in the pieces png
    init::rects(window.rectSources);

    SDL_Event event;

    double lastRefresh = tools::uptime();

    while(!state.quit)
    {
        while((tools::uptime() - lastRefresh < Delta))
        {
            //  https://i.redd.it/ayih4qogh2a51.png 
        }
        lastRefresh = tools::uptime();

        logic(input_handler(event), state);
        render(window, state);
    }

    SDL_DestroyWindow(window.window);
    SDL_Quit();

    return 0;
}

int WinMain(int argc, char **argv)
{
    return main(argc, argv);
}