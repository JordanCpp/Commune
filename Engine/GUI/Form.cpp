#include "Form.h"

using namespace GUI;

Form::Form(Graphics::Canvas* canvas):
	Widget(canvas, Graphics::Point(0, 0), Graphics::Point(canvas->Width(), canvas->Height()))
{
}

void Form::Draw()
{
	View()->FillRect(Area(), Graphics::Color(120, 120, 104));

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}