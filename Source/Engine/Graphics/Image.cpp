#include "Image.h"
#include <iostream>
#include <cassert>
#include <SDL2/SDL_image.h>

using namespace Arc;
using namespace Graphics;

Image::Image(Canvas* Source, Color transparency, const std::string& Name) :
    _Canvas(Source)
{
    _Surface = IMG_Load(Name.c_str());

    if (_Surface == nullptr)
    {
        std::cout << "IMG_Load: " << Name << IMG_GetError() << std::endl;
        std::terminate();
    }

    SDL_SetColorKey(_Surface, SDL_TRUE, SDL_MapRGB(_Surface->format, transparency.Red(), transparency.Green(), transparency.Blue()));

    _Texture = SDL_CreateTextureFromSurface(_Canvas->Render(), _Surface);

    SDL_QueryTexture(_Texture, nullptr, nullptr, &_Width, &_Height);

    if (_Texture == nullptr)
    {
        std::cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        std::terminate();
    }

    SDL_FreeSurface(_Surface);
}

Image::Image(Canvas* CanvasSource, SDL_Surface* SurfaceCanvas):
    _Canvas(CanvasSource),
    _Surface(SurfaceCanvas),
    _Texture(nullptr)
{
    assert(_Surface);

    SDL_SetColorKey(_Surface, SDL_TRUE, SDL_MapRGB(_Surface->format, 0, 0, 255));

    _Texture = SDL_CreateTextureFromSurface(_Canvas->Render(), _Surface);

    SDL_QueryTexture(_Texture, nullptr, nullptr, &_Width, &_Height);

    assert(_Texture);

    SDL_FreeSurface(_Surface);
}

Image::Image(Canvas* canvas, Color transparency, size_t w, size_t h, const std::vector<Color>& data):
_Canvas(canvas),
_Surface(nullptr),
_Texture(nullptr)
{

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    const uint32_t R_MASK = 0xff000000;
    const uint32_t G_MASK = 0x00ff0000;
    const uint32_t B_MASK = 0x0000ff00;
    const uint32_t A_MASK = 0x000000ff;
#else
    const uint32_t R_MASK = 0x000000ff;
    const uint32_t G_MASK = 0x0000ff00;
    const uint32_t B_MASK = 0x00ff0000;
    const uint32_t A_MASK = 0xff000000;
#endif

    _Surface = SDL_CreateRGBSurfaceFrom((void*)&data[0], w, h, 32, w * 4, R_MASK, G_MASK, B_MASK, A_MASK);

    if (_Surface == NULL)
    {
        std::cout << "SDL_CreateRGBSurfaceFrom: " << SDL_GetError() << std::endl;
    }

    SDL_SetColorKey(_Surface, SDL_TRUE, SDL_MapRGB(_Surface->format, transparency.Red(), transparency.Green(), transparency.Blue()));

    _Texture = SDL_CreateTextureFromSurface(_Canvas->Render(), _Surface);

    if (_Texture == NULL)
    {
        std::cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
    }

    SDL_QueryTexture(_Texture, nullptr, nullptr, &_Width, &_Height);

    SDL_FreeSurface(_Surface);
}

Image::~Image()
{
  SDL_DestroyTexture(_Texture);
}

void Image::Draw(Point Pt)
{
  SDL_Rect rt;

  rt.x = Pt.PosX();
  rt.y = Pt.PosY();
  rt.w = Width();
  rt.h = Height();

  SDL_RenderCopy(_Canvas->Render(), _Texture, nullptr, &rt);
}

void Image::Draw(Point Pt, Point Sz)
{
  SDL_Rect rt;

  rt.x = Pt.PosX();
  rt.y = Pt.PosY();
  rt.w = Sz.PosX();
  rt.h = Sz.PosY();

  SDL_RenderCopy(_Canvas->Render(), _Texture, nullptr, &rt);
}

int Image::Width()
{
  return _Width;
}

int Image::Height()
{
  return _Height;
}
