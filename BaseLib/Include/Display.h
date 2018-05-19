#pragma once


#include <SDL.h>
#include <string>

#include "MouseEventHandler.h"

class Display
{
public:
  Display(int width, int height, const std::string& title);

  void Clear(float r, float g, float b, float a);
  bool isClosed();
  void Update();

  int Height() const;
  int Width() const;

  virtual ~Display();
protected:
private:
  MouseEventHandler m_mouseEventHandler;
  SDL_Window* m_window;
  SDL_GLContext m_glContext;
  int m_width;
  int m_height;
  bool m_isClosed;
};