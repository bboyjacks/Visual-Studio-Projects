#include "MouseEventHandler.h"
#include <iostream>

MouseEventHandler::MouseEventHandler(int width, int height, Camera& camera) : m_camera(camera)
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
    const float directionLength = glm::length(m_vectorDirection);
    const glm::mat3 rotationMatrix = {
      glm::vec3(glm::cos(directionLength), -glm::sin(directionLength), 0.0f),
      glm::vec3(glm::sin(directionLength),  glm::cos(directionLength), 0.0f),
      glm::vec3(0.0f, 0.0f, 1.0f)
    };
    const glm::vec3 newPosition = rotationMatrix * m_camera.GetPosition();
    m_camera.SetPosition(newPosition);
    std::cout << "Magnitude: " << glm::length(m_vectorDirection) << std::endl;
    std::cout << m_vectorDirection.x << " , " << m_vectorDirection.y << std::endl;
    std::cout << newPosition.x << " , " << newPosition.y << " , " << newPosition.z << std::endl;
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
