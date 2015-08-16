#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams);

  void draw(TextureManager& TheTextureManager);
  void update();
  void clean();
};

#endif // ENEMY_H
