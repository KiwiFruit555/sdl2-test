#ifndef _KIWIINIT_H
#define _KIWIINIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <stdio.h>
#include <stdlib.h>

int init(SDL_Renderer *renderer, SDL_Rect winrect, SDL_Window *mainwindow);
int destruct(SDL_Renderer *renderer, SDL_Rect winrect, SDL_Window *mainwindow);

#endif // _KIWIINIT_H