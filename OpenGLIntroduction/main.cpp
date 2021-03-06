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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Display display(WIDTH, HEIGHT, "Hello world!");

    Mesh monkey("./monkey3.obj.txt");
    Shader shader("./basicShader");
    Texture texture("bricks.jpg");
    Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
    Transform transform;

    float counter = 0.0f;
    while (!display.isClosed())
    {
        display.Clear(0.0f, 0.0f, 0.3f, 1.0f);

        transform.GetRot().y = counter * 0.1;

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform, camera);
        monkey.Draw();
        display.Update();
        counter += 0.01f;
    }
    return 0;
}

