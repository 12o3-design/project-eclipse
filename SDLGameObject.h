#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams);

  virtual void draw(TextureManager& TheTextureManager);
  virtual void update();
  virtual void clean();

protected:
  int m_x;
  int m_y;

  int m_width;
  int m_height;

  int m_currentRow;
  int m_currentFrame;

  std::string m_textureID;

};

#endif
