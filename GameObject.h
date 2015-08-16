#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "LoaderParams.h"
#include "TextureManager.h"

class GameObject
{
public:

  virtual void draw(TextureManager& TheTextureManager) = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:
  GameObject(const LoaderParams* pParams) {}
  virtual ~GameObject() {}
};

#endif // define GAMEOBJECT_H
