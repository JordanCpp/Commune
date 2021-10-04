#include "Factory.h"

using namespace GUI;

Factory::Factory(Graphics::Canvas* canvas, Managers::TextManager* text):
	_Canvas(canvas),
	_TextManager(text)
{
}

Factory::~Factory()
{
	for (size_t i = 0; i < _Widgets.size(); i++)
	{
		delete _Widgets[i];
	}
}

Graphics::Canvas* GUI::Factory::View()
{
	return _Canvas;
}

Managers::TextManager* GUI::Factory::Text()
{
	return _TextManager;
}

Application* GUI::Factory::NewApplication()
{
	Application* ptr = new Application(_Canvas);

	_Widgets.push_back(ptr);

	return ptr;
}

Form* Factory::NewForm()
{
	Form* ptr = new Form(_Canvas);

	_Widgets.push_back(ptr);

	return ptr;
}

Button* Factory::NewButton(Graphics::Point pos, Graphics::Point size, const std::string& caption)
{
	Button* ptr = new Button(_Canvas, _TextManager, pos, size, caption);

	_Widgets.push_back(ptr);

	return ptr;
}

Label* Factory::NewLabel(Graphics::Point pos, Graphics::Point size, const std::string& caption)
{
	Label* ptr = new Label(_Canvas, _TextManager, pos, size, caption);

	_Widgets.push_back(ptr);

	return ptr;
}