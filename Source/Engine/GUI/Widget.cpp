#include "Widget.h"

using namespace Arc;
using namespace GUI;

Widget::Widget(Graphics::Canvas* canvas, Graphics::Point pos, Graphics::Point size):
	_Visible(true),
	Click(nullptr),
	_State(Normal),
	_Parent(nullptr),
	_Canvas(canvas),
	_Area(pos, size)
{
}

Widget::~Widget()
{
}

void GUI::Widget::On()
{
	_Visible = true;
}

void GUI::Widget::Off()
{
	_Visible = false;
}

bool Widget::Visible()
{
	return _Visible;
}

Graphics::Canvas* Widget::View()
{
	return _Canvas;
}

size_t Widget::State()
{
	return _State;
}

void Widget::State(size_t value)
{
	_State = value;
}

Widget* Widget::Parent()
{
	return _Parent;
}

void Widget::Parent(Widget* source)
{
	_Parent = source;
}

std::vector<Widget*>& Widget::Widgets()
{
	return _Widgets;
}

Graphics::Rect& Widget::Area()
{
	return _Area;
}

Widget* Widget::Contains(Graphics::Point pos)
{
	for (size_t i = 0; i < _Widgets.size(); i++)
	{
		if (_Widgets[i]->Area().Contains(pos))
		{
			if (_Widgets[i]->Contains(pos) != nullptr)
			{
				return _Widgets[i]->Contains(pos);
			}

			return _Widgets[i];
		}
	}

	return nullptr;
}

void Widget::Attach(Widget* source)
{
	source->Parent(this);
	Widgets().push_back(source);
}