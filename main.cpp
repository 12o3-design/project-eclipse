#include "Game.h"

int main (int argc, char* argv[])
{
  Game* TheGame = new Game();

  std::cout << "Game init attempt" << std::endl;
  if (TheGame->init("Chapter 1", 100,100,640,480,false))
  {
    std::cout << "Game init success" << std::endl;
    while (TheGame->isRunning())
    {
      TheGame->handleEvents();
      TheGame->update();
      TheGame->render();

      SDL_Delay(10);
    }
  }
  else
  {
    std::cout << "game init failure: " << SDL_GetError() << std::endl;
    return -1;
  }

  std::cout << "game closing..." << std::endl;
  TheGame->clean();
  delete TheGame;
  return 0;
}
