#include "Execute.h"
#include "UI/UI.h"
#include "UI/MainMenu.h"
#include "UI/Editor.h"
#include "UI/Dialog.h"

using namespace Fallout;

Execute::Execute(const std::string& path):
	_Settings(path),
	_Allocator(Arc::Allocators::Allocator::Mb* _Settings.GeneralSize()),
	_Canvas(_Settings.WindowSize(), _Settings.Fps(), _Settings.Title()),
	_Camera(Arc::Graphics::Point(0, 0), Arc::Graphics::Point(_Canvas.Width(), _Canvas.Height())),
	_MsgManager(_Settings.Path()),
	_FontManager(_Settings.Path()),
	_TextManager(&_Canvas, &_FontManager),
	_SpriteManager(_Settings.Path(), &_Canvas, Arc::Graphics::Color(255, 0, 255)),
	_ObjectManager(_Settings.Path(), &_Allocator, &_SpriteManager),
	_XmlManager(_Settings.Path()),
	_LanguageManager(_Settings.Path(), &_XmlManager),
	_Factory(&_Canvas, &_TextManager, &_LanguageManager),
	_Application(&_Canvas)
{
	_TextManager.Activate("Crosterian.ttf");

	UI::MainMenu* mainMenu = new UI::MainMenu(&_Factory, &_Application, &_SpriteManager);
	UI::Editor  * editor   = new UI::Editor(&_Factory, &_Application, &_Camera, &_SpriteManager, &_ObjectManager);
	UI::Dialog  * dialog   = new UI::Dialog(&_Factory, &_Application, &_SpriteManager);

	_Application.Attach(UI::UI::MainMenu, mainMenu);
	_Application.Attach(UI::UI::Editor, editor);
	_Application.Attach(UI::UI::Dialog, dialog);

	_Application.Activate(UI::UI::Editor);
}

void Execute::Run()
{
	SDL_Event report = { 0 };

	while (_Canvas.GetEvent(report))
	{
		_Application.Handler(report);
		_Application.Draw();
	}
}