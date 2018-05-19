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
#include "MouseEventHandler.h"

#define WIDTH 800
#define HEIGHT 600

#undef main

int main()
{
  Camera camera(glm::vec3(0.0f, 0.0f, -100.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
  MouseEventHandler mouseEventHandler(WIDTH, HEIGHT, camera);
  Display display(WIDTH, HEIGHT, "Hello world!", mouseEventHandler);

  Mesh cube("./Resource/roof.obj");
  Texture texture("./Resource/bricks.jpg");
  Shader shader("./Resource/basicShader");
  Transform transform;

  float counter = 0.0f;
  while (!display.isClosed())
  {
    display.Clear(1.0f, 1.0f, 1.0f, 1.0f);
    shader.Bind();
    texture.Bind(0);
    shader.Update(transform, camera);
    cube.Draw();
    display.Update();
    counter += 0.01f;
  }
  return 0;
}

