#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

class GameObject
{
public:
  GameObject();
  ~GameObject();

  virtual void load(int x, int y, int width, int height, std::string textureID);
  virtual void draw(SDL_Renderer* pRenderer);
  virtual void update();
  virtual void clean();

protected:
  std::string m_textureID;

  int m_currentFrame;
  int m_currentRow;

  int m_x;
  int m_y;

  int m_width;
  int m_height;

};

#endif // define GAMEOBJECT_H
