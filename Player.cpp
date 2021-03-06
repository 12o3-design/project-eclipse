#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw(SDL_Renderer* m_renderer, TextureManager* m_textureManager)
{
  SDLGameObject::draw(m_renderer, m_textureManager);
}

void Player::update()
{
  m_x -= 1;
  m_currentFrame = int (((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}
