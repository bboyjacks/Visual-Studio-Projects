#pragma once

#include <glm/glm.hpp>
#include <SDL.h>

class MouseEventHandler
{
public:
  MouseEventHandler(int width, int height);

  void WatchMouseOn(const SDL_MouseButtonEvent& mouseButtonEvent);
  void WatchMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent);
  void WatchMouseOff();

  virtual ~MouseEventHandler();
private:
  glm::vec2 m_vectorStartPoint;
  glm::vec2 m_vectorDirection;
  int m_width;
  int m_height;
  bool m_watchMouse;
};
