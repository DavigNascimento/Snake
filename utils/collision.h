#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

int collidesWithWindow(const SDL_Rect& rect, int windowWidth, int windowHeight);
bool checkCollision(SDL_Rect& a, SDL_Rect& b);

#endif
