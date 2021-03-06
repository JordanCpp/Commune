#include "Canvas3D.h"
#include <iostream>

using namespace Arc::Graphics;

Canvas3D::Canvas3D(Point size, size_t fps):
	_Size(size),
    _Running(true),
    _Fps(fps)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
    }

	_Window = SDL_CreateWindow("OpenGL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.PosX(), size.PosY(), SDL_WINDOW_OPENGL);

    if (_Window == nullptr)
    {
        std::cout << "SDL_CreateWindow: " << SDL_GetError() << std::endl;
    }

	_Context = SDL_GL_CreateContext(_Window);
}

bool Canvas3D::GetEvent(SDL_Event& Dest)
{
    SDL_Event event = { 0 };

    if (_Running == true)
    {
        size_t start = SDL_GetTicks();

        SDL_PollEvent(&event);

        Dest = event;

        if (event.type == SDL_QUIT)
        {
            _Running = false;
        }

        if (1000 / _Fps > SDL_GetTicks() - start)
        {
            SDL_Delay(1000 / _Fps - (SDL_GetTicks() - start));
        }

        SDL_GL_SwapWindow(_Window);
    }

    return _Running;
}

Canvas3D::~Canvas3D()
{
    SDL_GL_DeleteContext(_Context);
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}

size_t Canvas3D::Width()
{
    return _Size.PosX();
}

size_t Canvas3D::Height()
{
    return _Size.PosY();
}