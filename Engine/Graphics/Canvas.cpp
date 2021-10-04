#include "Canvas.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

using namespace Graphics;

Canvas::Canvas(Point Size, size_t Fps, const std::string& Title):
    _Running(true),
    _Fps(Fps),
    _Size(Size)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) 
    {
        std::cout << "IMG_Init: " << IMG_GetError() << std::endl;
    }

    _Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _Size.PosX(), _Size.PosY(), 0);

    if (_Window == nullptr)
    {
        std::cout << "SDL_CreateWindow: " << SDL_GetError() << std::endl;
    }

    _Render = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_ACCELERATED);

    if (_Render == nullptr)
    {
        std::cout << "SDL_CreateRenderer: " << SDL_GetError() << std::endl;
    }

    if (TTF_Init() != 0) 
    {
        std::cout << "Error: TTF_Init" << std::endl;
    }
}

Canvas::~Canvas()
{
    SDL_DestroyRenderer(_Render);
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}

size_t Graphics::Canvas::Width()
{
    return _Size.PosX();
}

size_t Graphics::Canvas::Height()
{
    return _Size.PosY();
}

bool Canvas::GetEvent(SDL_Event & Dest)
{
    SDL_Event event = {0};

    if (_Running == true)
    {
        SDL_RenderPresent(_Render);
        SDL_SetRenderDrawColor(_Render, 240, 240, 240, 0);
        SDL_RenderClear(_Render);

        size_t start  = SDL_GetTicks();

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
    }

    return _Running;
}

void Graphics::Canvas::StopEvent()
{
    _Running = false;
}

SDL_Renderer * Canvas::Render()
{
    return _Render;
}

SDL_Window* Graphics::Canvas::Window()
{
    return _Window;
}

void Canvas::FillRect(Rect& Rt, Color Cr)
{
  SDL_Rect Rectangle;

  Rectangle.x = Rt.PosX();
  Rectangle.y = Rt.PosY();
  Rectangle.w = Rt.Width();
  Rectangle.h = Rt.Height();

  SDL_SetRenderDrawColor(_Render, Cr.Red(), Cr.Green(), Cr.Blue(), Cr.Alpha());
  SDL_RenderFillRect(_Render, &Rectangle);
}

void Canvas::DrawRect(Rect Rt, Color Cr)
{
  SDL_Rect Rectangle;

  Rectangle.x = Rt.PosX();
  Rectangle.y = Rt.PosY();
  Rectangle.w = Rt.Width();
  Rectangle.h = Rt.Height();

  SDL_SetRenderDrawColor(_Render, Cr.Red(), Cr.Green(), Cr.Blue(), Cr.Alpha());
  SDL_RenderDrawRect(_Render, &Rectangle);
}

void Graphics::Canvas::DrawLine(Point first, Point last, Color color)
{
    SDL_SetRenderDrawColor(_Render, color.Red(), color.Green(), color.Blue(), color.Alpha());
    SDL_RenderDrawLine(_Render, first.PosX(), first.PosY(), last.PosX(), last.PosY());
}
