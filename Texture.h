#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>
#include <iostream>

class Texture
{
public:
  void setTexture(SDL_Texture* pTexture);
  SDL_Texture* getTexture();
  void clearTexture();

private:
  SDL_Texture* m_texture;
};

typedef std::shared_ptr<Texture> TexturePtr;

#endif //TEXTURE_H
