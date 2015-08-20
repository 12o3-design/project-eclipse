#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams)
{
  m_x = pParams->getX();
  m_y = pParams->getY();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_textureID = pParams->getTextureID();

  delete pParams;

  m_currentRow = 1;
  m_currentFrame = 1;

}
void SDLGameObject::draw(SDL_Renderer* m_renderer, TextureManager* m_textureManager)
{
  m_textureManager->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, m_renderer);
}

void SDLGameObject::update()
{

}

void SDLGameObject::clean()
{

}
