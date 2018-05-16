#pragma once


#include <SDL.h>
#include <string>

class Display
{
public:
    Display(int width, int height, const std::string& title);

    void Clear(float r, float g, float b, float a);
    bool isClosed();
    void Update();

    virtual ~Display();
protected:
private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};