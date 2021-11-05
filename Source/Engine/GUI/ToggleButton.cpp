#include "ToggleButton.h"

using namespace Arc;
using namespace GUI;

ToggleButton::ToggleButton(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption) :
	Widget(CanvasSource, pos, size),
	_State(ToggleButton::Off),
	_TextManager(TextManagerSource),
	_Caption(caption)
{
}

void ToggleButton::Draw()
{
	View()->FillRect(Area(), Graphics::Color(204, 204, 204));

	if (State() == Widget::Normal)
	{
		if (_State == ToggleButton::On)
		{
			View()->DrawRect(Area(), Graphics::Color(237, 28, 36));
		}
		else
		{
			View()->DrawRect(Area(), Graphics::Color(0, 0, 0));
		}
	}
	else if (State() == Widget::Hover)
	{
		View()->DrawRect(Area(), Graphics::Color(237, 28, 36));
	}
	else if (State() == Widget::Down)
	{
		View()->DrawRect(Area(), Graphics::Color(63, 72, 204));

		if (_State == ToggleButton::On)
		{
			_State = ToggleButton::Off;
		}
		else
		{
			_State = ToggleButton::On;
		}
	}
}