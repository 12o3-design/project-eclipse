#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <assert>

class Game
{
public:
  Game()
  {
    assert(!instantiated_);
    instantiated_ = true;
  };
  ~Game() {};

  void setup(const char* title, int xPos, int yPos, int width, int height, int flags);

  void handleInput();
  void update();
  void draw();

  void clean();

  bool isRunning() { return running_; }

private:

  static bool instantiated_;
  bool running_;

  SDL_Renderer* renderer_;
  SDL_Window* window_;



};

#endif // GAME_H
