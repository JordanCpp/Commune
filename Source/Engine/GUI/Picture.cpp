#include "Picture.h"

using namespace Arc;
using namespace GUI;

GUI::Picture::Picture(Graphics::Canvas* canvas, Graphics::Image* image, Graphics::Point pos, Graphics::Point size):
	Widget(canvas, pos, size),
	_Image(image)
{
}

void Picture::Draw()
{
	_Image->Draw(Graphics::Point(Area().PosX(), Area().PosY()), Graphics::Point(Area().Width(), Area().Height()));
}