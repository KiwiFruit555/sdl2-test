#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <stdio.h>
#include <stdlib.h>

#include "kiwifunc.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480

int init(SDL_Renderer *renderer, SDL_Rect winrect, SDL_Window *mainwindow) {
  // Initialize everything from SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "[ERROR] (Init) SDL_INIT_EVERYTHING: %s\n", SDL_GetError());
    destruct(renderer, winrect, mainwindow);
    return EXIT_FAILURE;
  }

  // Initialize the main window
  mainwindow = SDL_CreateWindow("KiUI Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  if (mainwindow == NULL) {
    fprintf(stderr, "[ERROR] (Init) SDL_CreateWindow: %s\n", SDL_GetError());
    destruct(renderer, winrect, mainwindow);
    return EXIT_FAILURE;
  }

  // Initialize the renderer
  renderer = SDL_CreateRenderer(mainwindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    fprintf(stderr, "[ERROR] (Init) SDL_CreateRenderer: %s\n", SDL_GetError());
    destruct(renderer, winrect, mainwindow);
    return EXIT_FAILURE;
  }

  // Initialize the window rectangle
  //winrect = (SDL_Rect) {0, 0, 640, 480};
  winrect.x = 0;
  winrect.y = 0;
  winrect.w = 640;
  winrect.h = 480;

  return EXIT_SUCCESS;
}

int destruct(SDL_Renderer *renderer, SDL_Rect winrect, SDL_Window *mainwindow) {
  if (renderer != NULL) SDL_DestroyRenderer(renderer);
  if (mainwindow != NULL) SDL_DestroyWindow(mainwindow);

  SDL_Quit();

  return EXIT_SUCCESS;
}