#include <SDL2/SDL.h>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init failed with error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "calculator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 600, SDL_WINDOW_SHOWN);

    if (!window)
    {
        cout << "window creation failed with error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    return 0;
}
