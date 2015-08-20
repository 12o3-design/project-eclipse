#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
public:

  Game()
  {
    assert (!m_instantiated);
    m_instantiated = true;
    TheTextureManager = &m_texManager;
  }

  bool init(const char* title, int xpos, int ypos,
    int width, int height, bool fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();

  bool isRunning() { return m_bRunning; }

private:

  static bool m_instantiated;

  bool m_bRunning;

  // game services

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

  int m_currentFrame;

  TextureManager m_texManager;
  TextureManager* TheTextureManager;

  std::vector<SDLGameObject*> m_gameObjects;
};

#endif // defined GAME_H
