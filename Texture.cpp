#include "Texture.h"

void Texture::assignTexture(SDL_Texture* pTexture)
{
  m_texture = pTexture;
}

SDL_Texture* getTexture()
{
  return m_texture;
}

void Texture::clearTexture()
{
  SDL_DestroyTexture(m_texture);
}
