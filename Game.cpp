#include "Game.h"
#include <iostream>

bool Game::instantiated_ = false;

void Game::setup(const char* title, int xPos, int yPos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SDL_Init success" << std::endl;
    // creates new window
    window_ = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    // check if window created
    if (window_ != 0)
    {
      std::cout << "SDL_CreateWindow success" << std::endl;
      // create renderer
      renderer_ = SDL_CreateRenderer(window_, -1, 0);
      // check if renderer is created
      if (renderer_ != 0)
      {
        std::cout << "SDL_CreateRenderer success" << std::endl;
        SDL_SetRenderDrawColor(renderer_, 255,255,255,255);
        running_ = true;
        instantiated_ = true;
      }
    }
  }

  else
  {
    std::cout << "SDL_Init failure" << std::endl;
  }

}

void Game::handleInput()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        running_ = false;
        break;
      default:
        break;
    }
  }
}

void Game::update()
{

}

void Game::draw()
{
  SDL_RenderClear(renderer_);

  SDL_RenderPresent(renderer_);
}

void Game::clean()
{
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
}
