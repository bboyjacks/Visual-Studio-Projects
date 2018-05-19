#include "Display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 8);

  m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  m_glContext = SDL_GL_CreateContext(m_window);
  m_isClosed = false;
  m_mouseEventHandler = new MouseEventHandler(width, height);

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

Display::~Display()
{
  delete(m_mouseEventHandler);
  SDL_GL_DeleteContext(m_glContext);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Display::isClosed()
{
  return m_isClosed;
}

void Display::Update()
{
  SDL_GL_SwapWindow(m_window);
  SDL_Event e;

  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
      m_isClosed = true;
    else if (e.type == SDL_MOUSEBUTTONDOWN)
      m_mouseEventHandler->WatchMouseOn(e.button);
    else if (e.type == SDL_MOUSEBUTTONUP)
      m_mouseEventHandler->WatchMouseOff();
    else if (e.type == SDL_MOUSEMOTION)
    {
      m_mouseEventHandler->WatchMotionEvent(e.motion);
    }
  }
}