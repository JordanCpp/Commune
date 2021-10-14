#include "Execute.h"
#include "UI/UI.h"
#include "UI/MainMenu.h"

using namespace Fallout;

Execute::Execute(const std::string& path):
	_Settings(path),
	_Canvas(_Settings.WindowSize(), _Settings.Fps(), _Settings.Title()),
	_Camera(Graphics::Point(0, 0), Graphics::Point(_Canvas.Width(), _Canvas.Height())),
	_FontManager(_Settings.Path()),
	_TextManager(&_Canvas, &_FontManager),
	_ImageManager(_Settings.Path(), &_Canvas, Graphics::Color(255, 0, 255)),
	_XmlManager(_Settings.Path()),
	_LanguageManager(_Settings.Path(), &_XmlManager),
	_Factory(&_Canvas, &_TextManager, &_LanguageManager)
{
	_TextManager.Activate("Crosterian.ttf");

	_Application = _Factory.NewApplication();

	UI::MainMenu* mainMenu = new UI::MainMenu(&_Factory, _Application, &_ImageManager);

	_Application->Attach(UI::UI::MainMenu, mainMenu);

	_Application->Activate(UI::UI::MainMenu);
}

void Execute::Run()
{
	SDL_Event report = { 0 };

	while (_Canvas.GetEvent(report))
	{
		_Application->Handler(report);
		_Application->Draw();
	}
}