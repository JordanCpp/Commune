#include "Point.h"

using namespace Arc;
using namespace Graphics;

Point::Point(size_t x, size_t y):
_PosX(x),
_PosY(y)
{
}

Point::~Point()
{
}

size_t Point::PosX()
{
  return _PosX;
}

size_t Point::PosY()
{
  return _PosY;
}

void Point::PosX(size_t x)
{
    _PosX = x;
}

void Point::PosY(size_t y)
{
    _PosY = y;
}
