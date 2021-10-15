#include "Button.h"

using namespace Arc;
using namespace GUI;

Button::Button(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption) :
	Widget(CanvasSource, pos, size),
	_TextManager(TextManagerSource),
	_Caption(caption)
{
}

void Button::Draw()
{
	View()->FillRect(Area(), Graphics::Color(204, 204, 204));

	if (State() == Widget::Normal)
	{
		View()->DrawRect(Area(), Graphics::Color(0, 0, 0));
	}
	else if (State() == Widget::Hover)
	{
		View()->DrawRect(Area(), Graphics::Color(237, 28, 36));
	}
	else if (State() == Widget::Down)
	{
		View()->DrawRect(Area(), Graphics::Color(63, 72, 204));
	}

	Graphics::Text* text = _TextManager->GetText(_Caption);
	size_t x = Area().PosX() + (Area().Width() / 2 - text->Width() / 2);
	size_t y = Area().PosY() + (Area().Height() / 2 - text->Height() / 2);
	text->Draw(Graphics::Point(x, y));
}