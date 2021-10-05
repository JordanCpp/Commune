#include "Window.h"

using namespace GUI;

Window::Window(Graphics::Canvas* canvas, Managers::TextManager* text, Graphics::Point pos, Graphics::Point size):
	Widget(canvas, pos, size),
	_TextManager(text)
{
}

void GUI::Window::Draw()
{
	View()->FillRect(Area(), Graphics::Color(120, 120, 104));
	View()->DrawRect(Area(), Graphics::Color(0, 0, 0));

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}