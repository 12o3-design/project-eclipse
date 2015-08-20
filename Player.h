#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);

  void draw(SDL_Renderer* m_renderer, TextureManager* m_textureManager);
  void update();
  void clean();

};

#endif
