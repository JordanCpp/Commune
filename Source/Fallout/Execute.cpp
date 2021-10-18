#include "Execute.h"
#include "UI/UI.h"
#include "UI/MainMenu.h"
#include "Allocators/System.h"
#include "Allocators/General.h"

using namespace Fallout;

Arc::Allocators::LinearAllocator* _General = nullptr;
Arc::Allocators::LinearAllocator* _System  = nullptr;

Execute::Execute(const std::string& path):
	_Settings(path),
	_Canvas(_Settings.WindowSize(), _Settings.Fps(), _Settings.Title()),
	_Camera(Arc::Graphics::Point(0, 0), Arc::Graphics::Point(_Canvas.Width(), _Canvas.Height())),
	_FontManager(_Settings.Path()),
	_TextManager(&_Canvas, &_FontManager),
	_SpriteManager(_Settings.Path(), &_Canvas, Arc::Graphics::Color(255, 0, 255)),
	_XmlManager(_Settings.Path()),
	_LanguageManager(_Settings.Path(), &_XmlManager),
	_Factory(&_Canvas, &_TextManager, &_LanguageManager)
{
	_System = new Arc::Allocators::LinearAllocator(Arc::Allocators::LinearAllocator::Mb * _Settings.SystemSize());
	_General = new Arc::Allocators::LinearAllocator(Arc::Allocators::LinearAllocator::Mb * _Settings.GeneralSize());

	_TextManager.Activate("Crosterian.ttf");

	_Application = _Factory.NewApplication();

	UI::MainMenu* mainMenu = new UI::MainMenu(&_Factory, _Application, &_SpriteManager);

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