#include "Execute.h"
#include "UI/UI.h"
#include "UI/MainMenu.h"
#include "UI/Editor.h"
#include "UI/Settings.h"

using namespace Disciples;

Execute::Execute(const std::string& StartPath):
	_Settings(StartPath),
	_Canvas(_Settings.WindowSize(), _Settings.Fps(), _Settings.Title()),
	_Camera(Arc::Graphics::Point(0, 0), Arc::Graphics::Point(_Canvas.Width(), _Canvas.Height())),
	_FontManager(_Settings.Path()),
	_TextManager(&_Canvas, &_FontManager),
	_ImageManager(_Settings.Path(), &_Canvas, Arc::Graphics::Color(255, 0, 255)),
	_XmlManager(_Settings.Path()),
	_LanguageManager(_Settings.Path(), &_XmlManager),
	_Factory(&_Canvas, &_TextManager, &_LanguageManager)
{
	_TextManager.Activate("Crosterian.ttf");

	_Application = _Factory.NewApplication();

	UI::MainMenu* mainMenu = new UI::MainMenu(&_Factory, _Application, &_ImageManager);
	UI::Editor* editor = new UI::Editor(&_Factory, &_ImageManager, _Application, &_Camera, new Game::Location(&_Camera, &_ImageManager));
	UI::Settings* settings = new UI::Settings(&_Factory);

	_Application->Attach(UI::UI::MainMenu, mainMenu);
	_Application->Attach(UI::UI::Editor, editor);
	_Application->Attach(UI::UI::Settings, settings);

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