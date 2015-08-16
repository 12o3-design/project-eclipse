#include "Game.h"

Game* g_game = 0;

int main (int argc, char* argv[])
{

  std::cout << "Game init attempt" << std::endl;
  if (TheGame::Instance()->init("Chapter 1", 100,100,640,480,false))
  {
    std::cout << "Game init success" << std::endl;
    while (TheGame::Instance()->isRunning())
    {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();

      SDL_Delay(10);
    }
  }
  else
  {
    std::cout << "game init failure: " << SDL_GetError() << std::endl;
    return -1;
  }

  std::cout << "game closing..." << std::endl;
  TheGame::Instance()->clean();

  return 0;
}
