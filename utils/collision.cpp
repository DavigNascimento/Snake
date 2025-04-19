#include "collision.h"

int collidesWithWindow(const SDL_Rect& rect, int windowWidth, int windowHeight) {
    int collision;
    if (rect.x < 0){
        collision = 1;
        return collision;
    }
    if (rect.y < 0){
        collision = 2;
        return collision;
    }
    if (rect.x + rect.w > windowWidth){
        collision = 3;
        return collision;
    }
    if (rect.y + rect.h > windowHeight){
        collision = 4;
        return collision;
    }
    return 0;
}

bool checkCollision(SDL_Rect& a, SDL_Rect& b)
{
    if (a.x + a.w <= b.x) return false;
    if (a.x >= b.x + b.w) return false;
    if (a.y + a.h <= b.y) return false;
    if (a.y >= b.y + b.h) return false;

    return true;
}

