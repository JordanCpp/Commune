#include "MainMenu.h"
#include "UI.h"

using namespace UI;

MainMenu::MainMenu(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Managers::ImageManager* images):
	Arc::GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application)
{
	factory->Language()->ActivateLang("Russian");
	factory->Language()->ActivateFile("Game");

	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Arc::Graphics::Point sz(200, 35);

	Arc::GUI::Button* newGame = factory->NewButton(Arc::Graphics::Point(x, y), sz, factory->Language()->GetString(1));
	y += sz.PosY() + s;

	Arc::GUI::Button* settings = factory->NewButton(Arc::Graphics::Point(x, y), sz, factory->Language()->GetString(2));
	y += sz.PosY() + s;

	Arc::GUI::Button* editor = factory->NewButton(Arc::Graphics::Point(x, y), sz, factory->Language()->GetString(3));
	y += sz.PosY() + s;

	Arc::GUI::Button* exit = factory->NewButton(Arc::Graphics::Point(x, y), sz, factory->Language()->GetString(4));
	y += sz.PosY() + s;

	this->Attach(newGame);
	this->Attach(settings);
	this->Attach(editor);
	this->Attach(exit);

	editor->Click = std::bind(&MainMenu::EditorOn, this, std::placeholders::_1);
	exit->Click = std::bind(&MainMenu::ExitOn, this, std::placeholders::_1);
	settings->Click = std::bind(&MainMenu::SettingsOn, this, std::placeholders::_1);

	_Screen = images->GetImage("Images\\", "MainMenu.jpeg");
}

void MainMenu::Draw()
{
	Arc::Graphics::Point screenSize(this->Area().Width(), this->Area().Height());
	_Screen->Draw(Arc::Graphics::Point(0, 0), screenSize);

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}

void MainMenu::EditorOn(Arc::Graphics::Point pos)
{
	_Application->Activate(UI::UI::Editor);
}

void MainMenu::ExitOn(Arc::Graphics::Point pos)
{
	View()->StopEvent();
}

void MainMenu::SettingsOn(Arc::Graphics::Point pos)
{
	_Application->Activate(UI::UI::Settings);
}