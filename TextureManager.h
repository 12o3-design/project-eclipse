#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>
#include <iostream>
#include <assert.h>

class TextureManager
{
public:
  TextureManager()
  {
    assert(!instantiated);
    instantiated = true;
  }
  ~TextureManager() {}
  bool load(std::string filename, std::string id,
    SDL_Renderer* pRenderer);

  void draw(std::string id, int x, int y, int width, int height,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void drawFrame(std::string id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderer,
    SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
  static bool instantiated;
  std::map<std::string, SDL_Texture*> m_textureMap;
};

#endif // define TEXTURE_H
