#ifndef SNAKE
#define SNAKE

#include <SDL2/SDL.h>
#include <SDL_rect.h>
#include <SDL_surface.h>
#include <array>
#include <cstdio>
#include <vector>
#include "../utils/moveRect.h"
#include "../utils/collision.h"

class Snake{
private:
    std::vector<SDL_Rect> snake;
    std::array<int, 3> color;
    int size;

public:
    Snake(int size = 20)
    {
        this->size = size;
        color[0] = 70;
        color[1] = 255;
        color[2] = 70;
        snake.push_back({0, 0, size, size});
    }

    void fill(SDL_Surface *surface)
    {
        for(int i = 0; i < snake.size(); i++)
        {
            SDL_FillRect(surface, &snake[i], SDL_MapRGB(surface->format, color[0], color[1], color[2]));
        }
    }

    void move(int Wwidth, int Wheight, int direction, int rate)
    {
        SDL_Rect lastPart, tmpRect = snake[0];
        if(direction == 1) tmpRect.x += rate;
        if(direction == 2) tmpRect.x -= rate;
        if(direction == 3) tmpRect.y -= rate;
        if(direction == 4) tmpRect.y += rate;

        if(!collidesWithWindow(tmpRect, Wwidth, Wheight))
        {
            for (int i = snake.size() - 1; i > 0; --i)
            {
                snake[i] = snake[i - 1];
            }
            snake[0] = tmpRect;
        }

    }

    SDL_Rect* get_head()
    {
        return &snake[0];
    }

    void grow(int Wwidth, int Wheight, int direction, int rate)
    {
        SDL_Rect tail = snake.back();
        snake.push_back(tail);
    }
};

#endif // !SNAKE
