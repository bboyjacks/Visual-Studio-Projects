#include "MouseEventHandler.h"
#include <iostream>

MouseEventHandler::MouseEventHandler(const Display& display)
{
  m_display = display;
  m_watchMouse = false;
}

void MouseEventHandler::WatchMouseOn(const SDL_MouseButtonEvent& mouseButtonEvent)
{
  m_vectorStartPoint = glm::vec2(mouseButtonEvent.x, mouseButtonEvent.y);
  m_watchMouse = true;
}

void MouseEventHandler::WatchMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent)
{
  if (m_watchMouse)
  {
    m_vectorDirection = glm::vec2(mouseMotionEvent.x, mouseMotionEvent.y) - m_vectorStartPoint;
    std::cout << "<" << m_vectorDirection.x << " , " << m_vectorDirection.y << ">" << std::endl;
  }
}

void MouseEventHandler::WatchMouseOff()
{
  m_vectorStartPoint = glm::vec2();
  m_watchMouse = false;
}

MouseEventHandler::~MouseEventHandler()
{
}
