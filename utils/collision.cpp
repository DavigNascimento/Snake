#include "collision.h"

bool collidesWithWindow(const SDL_Rect& rect, int windowWidth, int windowHeight) {
    if (rect.x < 0) return true;
    if (rect.y < 0) return true;
    if (rect.x + rect.w > windowWidth) return true;
    if (rect.y + rect.h > windowHeight) return true;
    return false;
}

bool checkCollision(SDL_Rect& a, SDL_Rect& b)
{
    if (a.x + a.w <= b.x) return false;
    if (a.x >= b.x + b.w) return false;
    if (a.y + a.h <= b.y) return false;
    if (a.y >= b.y + b.h) return false;

    return true;
}

