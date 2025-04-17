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
        std::uniform_int_distribution<> randX(50, Wwidth);
        std::uniform_int_distribution<> randY(50, Wheight);

        apple.x = randX(gen);
        apple.y = randY(gen);
    }

    void fill(SDL_Surface *surface)
    {
        SDL_FillRect(surface, &apple, SDL_MapRGB(surface->format, color[0], color[1], color[2]));
    }

    void spawn(SDL_Surface *surface, int Wwidth, int Wheight)
    {
        generate(Wwidth, Wheight);
        fill(surface);
    }

    SDL_Rect* get(){
        return &apple;
    }

};

#endif
