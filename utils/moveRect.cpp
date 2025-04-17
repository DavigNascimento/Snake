#include "moveRect.h"

void moveRect(SDL_Rect* rect, SDL_Keycode key) {
    int rate = 10;
    switch (key) {
        case SDLK_UP:    rect->y -= rate; break;
        case SDLK_DOWN:  rect->y += rate; break;
        case SDLK_LEFT:  rect->x -= rate; break;
        case SDLK_RIGHT: rect->x += rate; break;
    }
}
