#include "TextureManager.h"

bool TextureManager::instantiated = false;

TextureManager::~TextureManager()
{
  std::cout << "Texture Manager dtor" << std::endl;
  for (auto const& p : m_textureMap)
  {
    std::cout << "destroying " << p.second << " texture" << std::endl;
    SDL_DestroyTexture(p.second);
  }
  m_textureMap.clear();
}

bool TextureManager::load(std::string filename, std::string id, SDL_Renderer* pRenderer)
{
  // find if texture already loaded
  /*
  auto texIterator = m_textureMap.find(filename);
  if(texIterator != m_textureMap.end())
  {
    return texIterator.second;
  }
  */

  // loads image as SDL surface
  SDL_Surface* pTempSurface = IMG_Load(filename.c_str());

  if (pTempSurface == 0)
  {
    return false;
  }

  // makes new texture from surface
  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

  SDL_FreeSurface (pTempSurface);



  // texture loaded, add to list
  if (pTexture != 0)
  {
    m_textureMap[id] = pTexture;
    return true;
  }

  // something went wrong
  return false;

}

void TextureManager::draw(std::string id, int x, int y,
  int width, int height, SDL_Renderer* pRenderer,
  SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y,
  int width, int height, int currentRow, int currentFrame,
  SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect,
    0, 0, flip);

}
