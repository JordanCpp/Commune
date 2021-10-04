#include "Rect.h"

using namespace Graphics;

Rect::Rect(size_t x, size_t y, size_t w, size_t h):
    _PosX(x),
    _PosY(y),
    _Width(w),
    _Height(h)
{
}

Graphics::Rect::Rect(Point pos, Point size):
    _PosX(pos.PosX()),
    _PosY(pos.PosY()),
    _Width(size.PosX()),
    _Height(size.PosY())
{
}

Rect::Rect():
    _PosX(0),
    _PosY(0),
    _Width(0),
    _Height(0)
{
}

bool Rect::Contains(Point Pt)
{
  return Pt.PosX() >= _PosX && Pt.PosY()  >= _PosY && Pt.PosX() <= _PosX + _Width && Pt.PosY() <= _PosY + _Height;
}

size_t Rect::PosX()
{
  return _PosX;
}

size_t Rect::PosY()
{
  return _PosY;
}

size_t Rect::Width()
{
  return _Width;
}

size_t Rect::Height()
{
  return _Height;
}

void Rect::PosX(size_t value)
{
    _PosX = value;
}

void Rect::PosY(size_t value)
{
    _PosY = value;
}

void Rect::Width(size_t value)
{
    _Width = value;
}

void Rect::Height(size_t value)
{
    _Height = value;
}