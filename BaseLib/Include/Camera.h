#pragma once

#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

class Camera
{
public:
  Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
  {
    m_perspective = glm::perspective(fov, aspect, zNear, zFar);
    m_position = pos;
    m_forward = glm::vec3(0, 0, 1);
    m_up = glm::vec3(0, 1, 0);
    m_leftAngle = 0.0f;
    m_distance = m_position.z;
  }

  inline glm::mat4 GetViewProjection() const
  {
    return m_perspective * glm::lookAt(m_position, glm::vec3(0,0,0), m_up);
  }

  inline void MoveLeft()
  {
    m_leftAngle += 0.1f;
    m_position.z = m_distance * glm::cos(m_leftAngle);
    m_position.x = m_distance * glm::sin(m_leftAngle);
    if (m_leftAngle > 2 * glm::pi<float>())
      m_leftAngle = 0.0f;
  }

private:
  glm::mat4 m_perspective;
  glm::vec3 m_position;
  glm::vec3 m_forward;
  glm::vec3 m_up;
  float m_leftAngle;
  float m_distance;
};
