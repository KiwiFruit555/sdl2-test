#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "kiwifunc.h"

int running            = 1;    // Is this program running?
SDL_Renderer *renderer = NULL; // Renderer
SDL_Rect winrect;              // How big is the window?
SDL_Window *mainwindow = NULL; // Window

int render(void* data) {
  (void) data;
  //while (running) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &winrect);

    // Custom rendering

    SDL_RenderPresent(renderer);
    SDL_Delay(25);
  //}

  return EXIT_SUCCESS;
}

int run(void) {
  SDL_Event event;
  Uint64 start;
  Uint64 end;
  float elapsedMS;
  //SDL_Thread *rendering = SDL_CreateThread(render, "Rendering", NULL);

  while (running) {
    start = SDL_GetPerformanceCounter();
    //SDL_WaitEvent(&event);
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) running = 0;
      //if (event.type == SDL_MOUSEBUTTONDOWN)
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_F1) running = 0; // for no window manager running
      }
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &winrect);

    // Custom rendering

    end = SDL_GetPerformanceCounter();
    elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
    SDL_Delay(floor(16.666f - elapsedMS));

    SDL_RenderPresent(renderer);
  }

  //SDL_WaitThread(rendering, NULL);

  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  // Don't want to do anything with them, but don't want complaints
  (void) argc;
  (void) argv;

  init(renderer, winrect, mainwindow);

  run();

  destruct(renderer, winrect, mainwindow);

  return EXIT_SUCCESS;
}