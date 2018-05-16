// OpenGL_Prototype_1.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <iostream>
#include "Camera.h"
#include "Display.h"
#include "Mesh.h"
#include "Shaders.h"
#include "Texture.h"
#include "Transform.h"

#define WIDTH 800
#define HEIGHT 600

#undef main

std::vector<Vertex> CreateCubeVertices()
{
  std::vector<Vertex> vertices = {
    Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3(-0.5,-0.5, 0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3( 0.5,-0.5, 0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3( 0.5, 0.5, 0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3(-0.5, 0.5,-0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3(-0.5,-0.5,-0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3( 0.5,-0.5,-0.5), glm::vec4(1, 0, 0, 1)),
    Vertex(glm::vec3( 0.5, 0.5,-0.5), glm::vec4(1, 0, 0, 1))
  };
  return vertices;
}

std::vector<unsigned int> GetCubeIndices()
{
  std::vector<unsigned int> indices = {
    0, 1, 2, 0,
    0, 3, 2, 0,
    3, 2, 6, 3,
    6, 7, 3, 6,
    7, 5, 6, 7,
    7, 5, 4, 7,
    4, 1, 5, 4,
    4, 1, 0, 4,
    4, 3, 0, 4,
    4, 3, 7, 4,
    5, 1, 2, 5,
    5, 2, 6, 5
  };
  return indices;
}

int main()
{
  Display display(WIDTH, HEIGHT, "Hello world!");

  std::vector<Vertex> vertices = CreateCubeVertices();
  std::vector<unsigned int> indices = GetCubeIndices();

  Mesh cube(&vertices[0], vertices.size(), &indices[0], indices.size());

  Shader shader("./basicShader");
  Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
  Transform transform;

  float counter = 0.0f;
  while (!display.isClosed())
  {
    display.Clear(0.0f, 0.0f, 0.3f, 1.0f);

    transform.GetRot().y = counter * 0.1;
    shader.Bind();
    shader.Update(transform, camera);
    cube.Draw();
    display.Update();
    counter += 0.01f;
  }
  return 0;
}

