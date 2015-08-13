#include <iostream>
#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::init(const char* title, int xpos, int ypos,
  int width, int height, bool fullscreen)
{
  int flags = 0;

  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  // attempt to init SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SDL init success" << std::endl;

    // init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    // if window init success
    if (m_pWindow != 0)
    {
      std::cout << "Window init success" << std::endl;

      // init the renderer
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      // if renderer init success
      if (m_pRenderer != 0)
      {
        std::cout << "Renderer init success" << std::endl;

        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
      }
      else
      {
        std::cout << "Renderer init fail" << std::endl;
        return false;
      }
    }
    else
    {
      std:: cout << "Window init fail" << std::endl;
      return false;
    }
  }
  else
  {
    std::cout << "SDL init fail" << std::endl;
    return false;
  }

  std::cout << "init success" << std::endl;
  m_bRunning = true;


// testing

  if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
  {
    return false;
  }
  
  m_go = new GameObject();
  m_player = new Player();
  m_enemy = new Enemy();


  m_go->load(100,100,128,82,"animate");
  m_player->load(300,300,128,82,"animate");
  m_enemy->load(0,0, 128, 82, "animate");

  m_gameObjects.push_back(m_go);
  m_gameObjects.push_back(m_player);
  m_gameObjects.push_back(m_enemy);

  return true;
}


void Game::render()
{
  // clear to draw color
  SDL_RenderClear(m_pRenderer);

  // loop and draw objects
  for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw(m_pRenderer);
  }

  // draw to screen
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;

      default:
        break;
    }
  }

}

void Game::clean()
{
  std::cout << "cleaning game" << std::endl;
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
