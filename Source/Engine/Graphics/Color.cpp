#include "Color.h"

using namespace Arc;
using namespace Graphics;

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a):
    _Red(r),
    _Green(g),
    _Blue(b),
    _Alpha(a)
{
}

Color::~Color()
{
}

uint8_t Color::Red()
{
    return _Red;
}

uint8_t Color::Green()
{
    return _Green;
}

uint8_t Color::Blue()
{
    return _Blue;
}

uint8_t Color::Alpha()
{
    return _Alpha;
}
