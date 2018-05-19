#include "MouseEventHandler.h"
#include <iostream>

MouseEventHandler::MouseEventHandler(int width, int height, Camera& camera) : m_camera(camera)
{
  m_width = width;
  m_height = height;
  m_watchMouseLeft = false;
  m_watchMouseRight = false;
}

void MouseEventHandler::WatchMouseOn(const SDL_MouseButtonEvent& mouseButtonEvent)
{
  m_vectorStartPoint = glm::vec2(mouseButtonEvent.x, mouseButtonEvent.y);
  if (mouseButtonEvent.button == SDL_BUTTON_LEFT)
    m_watchMouseLeft = true;
  else if (mouseButtonEvent.button == SDL_BUTTON_RIGHT)
    m_watchMouseRight = true;
}

void MouseEventHandler::WatchMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent)
{
  if (m_watchMouseLeft)
    m_camera.MoveHorizontal();
  else if (m_watchMouseRight)
    m_camera.MoveVertical();
}

void MouseEventHandler::WatchMouseOff()
{
  m_vectorStartPoint = glm::vec2(0, 0);
  m_watchMouseLeft = false;
  m_watchMouseRight = false;
}

MouseEventHandler::~MouseEventHandler()
{
}
