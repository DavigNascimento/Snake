
#include <SDL_keycode.h>
#include <SDL_rect.h>
#include <SDL_timer.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "utils/moveRect.h"
#include "utils/collision.h"

#define WIDTH 1200
#define HEIGHT 600

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

    SDL_Rect player = {0, 0, 10, 10};
    SDL_Rect rect = {100, 100, 100, 100};
    int lastMove = 1;
    
    int running = 1;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;

                if(key == SDLK_w) lastMove = 3;
                if(key == SDLK_a) lastMove = 2;
                if(key == SDLK_s) lastMove = 4;
                if(key == SDLK_d) lastMove = 1;
                
                if (key == SDLK_q) {
                    running = 0;
                }
            }
        }

        SDL_Rect tmpRect = player;
        int rate = 10;
        if(lastMove == 1) tmpRect.x += rate;
        if(lastMove == 2) tmpRect.x -= rate;
        if(lastMove == 3) tmpRect.y -= rate;
        if(lastMove == 4) tmpRect.y += rate;
        
        if(!collidesWithWindow(tmpRect, WIDTH, HEIGHT) & !checkCollision(tmpRect, rect)){
            player.x = tmpRect.x;
            player.y = tmpRect.y;
        }


        SDL_FillRect(surface, &player, SDL_MapRGB(surface->format, 255, 155, 155));
        SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 255, 255, 255));
        SDL_UpdateWindowSurface(window);
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0,0,0) );

        SDL_Delay(100);
    }



    return 0;
}
