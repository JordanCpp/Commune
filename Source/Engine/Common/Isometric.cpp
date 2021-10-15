#include "Isometric.h"

using namespace Arc;
using namespace Common;

Graphics::Point Isometric::CartesianToIsometric(Graphics::Point pt)
{
	size_t x = pt.PosX() - pt.PosY();
	size_t y = (pt.PosX() + pt.PosY()) / 2;

	return Graphics::Point(x, y);
}

Graphics::Point Isometric::IsometricToCartesian(Graphics::Point pt)
{
	size_t x = (2 * pt.PosY() + pt.PosX()) / 2;
	size_t y = (2 * pt.PosY() - pt.PosX()) / 2;

	return Graphics::Point(x, y);
}