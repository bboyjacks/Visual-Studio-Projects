#include "MouseEventHandler.h"
#include <iostream>

MouseEventHandler::MouseEventHandler(int width, int height)
{
  m_width = width;
  m_height = height;
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
    m_vectorDirection = glm::vec2(m_vectorDirection.x / m_width, m_vectorDirection.y / m_height);
    std::cout << m_vectorDirection.x << " , " << m_vectorDirection.y << std::endl;
  }
}

void MouseEventHandler::WatchMouseOff()
{
  m_vectorStartPoint = glm::vec2(0, 0);
  m_watchMouse = false;
}

MouseEventHandler::~MouseEventHandler()
{
}
