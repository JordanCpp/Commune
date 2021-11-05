#include "Canvas3D.h"

using namespace Arc::Graphics;

Canvas3D::Canvas3D(Point size, size_t fps):
	_Size(size),
    _Running(true),
    _Fps(fps)
{
	_Window = SDL_CreateWindow("OpenGL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.PosX(), size.PosY(), SDL_WINDOW_OPENGL);

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

size_t Canvas3D::Width()
{
    return _Size.PosX();
}

size_t Canvas3D::Height()
{
    return _Size.PosY();
}