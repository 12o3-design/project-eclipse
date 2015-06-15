#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();

  void init() { m_bRunning = true; }

  void render();
  void update();
  void handleEvents();
  void clean();

  bool isRunning() { return m_bRunning; }

private:
  bool m_bRunning;
  
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
};

#endif // defined GAME_H
