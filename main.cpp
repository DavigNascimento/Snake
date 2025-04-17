#include <SDL_keycode.h>
#include <SDL_rect.h>
#include <SDL_timer.h>
#include <cstdlib>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "entities/snake.h"
#include "entities/apple.h"
#include "utils/collision.h"

#define WIDTH 1200
#define HEIGHT 600
#define SIZE 20

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    Snake snake(SIZE);
    Apple apple(SIZE);


    int rate = 20;
    int direction = 1;
    bool hasApple = false;
    SDL_Event event;

    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;

                if(key == SDLK_w & direction != 4) direction = 3;
                if(key == SDLK_a & direction != 1) direction = 2;
                if(key == SDLK_s & direction != 3) direction = 4;
                if(key == SDLK_d & direction != 2) direction = 1;

                if (key == SDLK_q) {
                    running = 0;
                }
            }
        }

        if(!hasApple)
        {
            apple.spawn(surface, WIDTH, HEIGHT);
            hasApple = true;
        }

        if(checkCollision(*snake.get_head(), *apple.get()))
        {

            snake.grow(WIDTH, HEIGHT, direction, rate);
            apple.spawn(surface, WIDTH, HEIGHT);
        }

        snake.move(WIDTH, HEIGHT, direction, rate);

        snake.fill(surface);
        apple.fill(surface);
        SDL_UpdateWindowSurface(window);

        // WIPE SCREEN
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 150, 150, 250));

        SDL_Delay(50);
    }
    return 0;
}
