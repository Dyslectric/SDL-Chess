#include "tools.h"

double tools::uptime()
{
    double t = SDL_GetTicks();
    t *= 0.001;
    return t;
}