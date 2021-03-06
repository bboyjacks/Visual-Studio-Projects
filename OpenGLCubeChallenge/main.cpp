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
    Vertex(glm::vec3(-0.5, 0.5, 0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3(-0.5,-0.5, 0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3( 0.5,-0.5, 0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3( 0.5, 0.5, 0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3(-0.5, 0.5,-0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3(-0.5,-0.5,-0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3( 0.5,-0.5,-0.5), glm::vec2(1, 0)),
    Vertex(glm::vec3( 0.5, 0.5,-0.5), glm::vec2(1, 0))
  };
  return vertices;
}

std::vector<unsigned int> GetCubeIndices()
{
  std::vector<unsigned int> indices = {
    0, 1, 2,
    2, 0, 3,
    3, 2, 6,
    6, 3, 7,
    7, 6, 5,
    5, 7, 4,
    4, 5, 1,
    1, 4, 0,
    0, 3, 7,
    7, 0, 4,
    1, 5, 2,
    2, 5, 6
  };
  return indices;
}

int main()
{
  Display display(WIDTH, HEIGHT, "Hello world!");

  Mesh cube("./roof.obj");
  Texture texture("./bricks.jpg");
  Shader shader("./basicShader");
  Camera camera(glm::vec3(0, 0, -100), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
  Transform transform;

  float counter = 0.0f;
  while (!display.isClosed())
  {
    display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

    transform.GetRot().z = counter * 0.1;
    transform.GetRot().y = counter * 0.1;
    shader.Bind();
    texture.Bind(0);
    shader.Update(transform, camera);
    cube.Draw();
    display.Update();
    counter += 0.01f;
  }
  return 0;
}

