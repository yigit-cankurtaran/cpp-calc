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

    // window title, x position, y position, x size, y size, display window
    // CreateWindow returns a pointer
    SDL_Window *window = SDL_CreateWindow(
        "calculator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 600, SDL_WINDOW_SHOWN);

    if (!window)
    {
        cout << "window creation failed with error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // -1 = first available driver that works
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "renderer creation failed with error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event; // anything in the program sdl can detect (key presses mouse clicks etc)
    while (running)
    {
        while (SDL_PollEvent(&event)) // we pass in address so PollEvent can fill it with data
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // black screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // buttons

        // renderer, gray (100 on rgb each), 255 opacity
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

        // button placement x, button placement y, button xlen, button ylen

        SDL_Rect button1 = {50, 200, 80, 80};
        SDL_Rect button2 = {150, 200, 80, 80};
        SDL_Rect button3 = {250, 200, 80, 80};

        SDL_RenderFillRect(renderer, &button1);
        SDL_RenderFillRect(renderer, &button2);
        SDL_RenderFillRect(renderer, &button3);

        SDL_RenderPresent(renderer);
    }

    // cleanup

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
