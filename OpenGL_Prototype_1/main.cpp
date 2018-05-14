// OpenGL_Prototype_1.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include "Display.h"
#include <iostream>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    Display display(400, 400, "Hello world!");
    while (!display.isClosed())
    {
        display.Clear(0.0f, 0.0f, 0.3f, 1.0f);
        display.Update();
    }
    return 0;
}

