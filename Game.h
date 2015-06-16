#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "TextureManager.h"

class Game
{
public:
  Game();
  ~Game();

  bool init(const char* title, int xpos, int ypos,
    int width, int height, bool fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();

  bool isRunning() { return m_bRunning; }

private:
  bool m_bRunning;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;

  int m_currentFrame;
};

#endif // defined GAME_H
