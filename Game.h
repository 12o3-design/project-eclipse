#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }

  bool init(const char* title, int xpos, int ypos,
    int width, int height, bool fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();

  bool isRunning() { return m_bRunning; }

  SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
  Game();
  ~Game() { delete s_pInstance; }

  static Game* s_pInstance;

  bool m_bRunning;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

  int m_currentFrame;

  TextureManager TheTextureManager;

  std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif // defined GAME_H
