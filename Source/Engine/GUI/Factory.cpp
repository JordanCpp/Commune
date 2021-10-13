#include "Factory.h"

using namespace GUI;

Factory::Factory(Graphics::Canvas* canvas, Managers::TextManager* text, Managers::LanguageManager* language):
	_Canvas(canvas),
	_TextManager(text),
	_LanguageManager(language)
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

Managers::LanguageManager* GUI::Factory::Language()
{
	return _LanguageManager;
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

Window* Factory::NewWindow(Graphics::Point pos, Graphics::Point size)
{
	Window* ptr = new Window(_Canvas, _TextManager, pos, size);
		
	_Widgets.push_back(ptr);

	return ptr;
}

Picture* Factory::NewPicture(Graphics::Point pos, Graphics::Point size, Graphics::Image* image)
{
	Picture* ptr = new Picture(_Canvas, image, pos, size);

	_Widgets.push_back(ptr);

	return ptr;
}