#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw(SDL_Renderer* m_renderer, TextureManager* m_textureManager)
{
  SDLGameObject::draw(m_renderer, m_textureManager);
}

void Enemy::update()
{
  m_y += 1;
  m_x += 1;
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}
