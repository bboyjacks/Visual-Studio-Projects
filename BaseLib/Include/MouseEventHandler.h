#pragma once

#include <glm/glm.hpp>
#include <SDL.h>
#include "Camera.h"
#include "Transform.h"

class MouseEventHandler
{
public:
  MouseEventHandler(int width, int height, Camera& camera);

  void WatchMouseOn(const SDL_MouseButtonEvent& mouseButtonEvent);
  void WatchMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent);
  void WatchMouseOff();

  virtual ~MouseEventHandler();
private:
  Camera& m_camera;
  glm::vec2 m_vectorStartPoint;
  glm::vec2 m_vectorDirection;
  glm::vec2 m_transform;
  int m_width;
  int m_height;
  bool m_watchMouse;
};

