#include <SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main (int argc, char* argv[])
{
  // init SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    // if succeeded, create window
    g_pWindow = SDL_CreateWindow("Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }

  else
  {
    // SDL could not init
    return 1;
  }

  // init succeeded, draw to window

  // set window to black
  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  // clear window to black
  SDL_RenderClear(g_pRenderer);

  // show window
  SDL_RenderPresent(g_pRenderer);

  // delay before quitting
  SDL_Delay(5000);

  // clean up
  SDL_Quit();

  return 0;

}
