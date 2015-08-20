#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);

  void draw(SDL_Renderer* m_renderer, TextureManager* m_textureManager);
  void update();
  void clean();
};

#endif // ENEMY_H
