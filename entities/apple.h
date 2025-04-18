#ifndef APPLE
#define APPLE

#include <SDL2/SDL.h>
#include <array>
#include <random>

class Apple{
private:
    SDL_Rect apple;
    std::array<int, 3> color;
    int size;

public:

    Apple(int size)
    {
        color = {205, 25, 25};
        this->size = size;
        this->apple = {0, 0, size, size};
    };

    void generate(int Wwidth, int Wheight)
    {

        std::random_device rd;
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> randX(50, Wwidth-50);
        std::uniform_int_distribution<> randY(50, Wheight-50);

        apple.x = randX(gen);
        apple.y = randY(gen);
    }

    void fill(SDL_Surface *surface)
    {
        Uint32 pixelColor = SDL_MapRGB(surface->format, color[0], color[1], color[2]);
        drawFilledCircle(surface, apple.x + size / 2, apple.y + size / 2, size / 2, pixelColor);
    }

    void spawn(SDL_Surface *surface, int Wwidth, int Wheight)
    {
        generate(Wwidth, Wheight);
        fill(surface);
    }

    SDL_Rect* get(){
        return &apple;
    }

    void drawFilledCircle(SDL_Surface* surface, int cx, int cy, int radius, Uint32 color) {
        for (int y = -radius; y <= radius; y++) {
            for (int x = -radius; x <= radius; x++) {
                if (x*x + y*y <= radius*radius) {
                    int drawX = cx + x;
                    int drawY = cy + y;
                    if (drawX >= 0 && drawX < surface->w && drawY >= 0 && drawY < surface->h) {
                        Uint32* pixels = (Uint32*)surface->pixels;
                        pixels[drawY * surface->w + drawX] = color;
                    }
                }
            }
        }
    }

};

#endif
