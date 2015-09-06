#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Game* TheGame = new Game();

  std::cout << "making game" << std::endl;

  TheGame->setup("Project Eclipse PRE-ALPHA", 100, 100, 640, 480, 0);

// main game loop
  while (TheGame->isRunning())
  {
    TheGame->handleInput();
    TheGame->update();
    TheGame->draw();
  }

// cleanup
  TheGame->clean();
  delete TheGame;

  return 0;
}
