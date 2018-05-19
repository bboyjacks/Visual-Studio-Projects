#pragma once

#include <glm/glm.hpp>
#include <SDL.h>
#include "Display.h"

class MouseEventHandler
{
public:
  MouseEventHandler(const Display& display);

  void WatchMouseOn(const SDL_MouseButtonEvent& mouseButtonEvent);
  void WatchMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent);
  void WatchMouseOff();

  virtual ~MouseEventHandler();
private:
  Display* m_display;
  glm::vec2 m_vectorStartPoint;
  glm::vec2 m_vectorDirection;
  bool m_watchMouse;
};

