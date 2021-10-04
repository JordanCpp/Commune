#include "MainMenu.h"
#include "UI.h"

using namespace UI;

MainMenu::MainMenu(GUI::Factory* factory, GUI::Application* application, Managers::ImageManager* images):
	GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application)
{
	factory->Language()->ActivateLang("Russian");
	factory->Language()->ActivateFile("Game");

	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Graphics::Point sz(200, 35);

	GUI::Button* newGame = factory->NewButton(Graphics::Point(x, y), sz, factory->Language()->GetString(1));
	y += sz.PosY() + s;

	GUI::Button* settings = factory->NewButton(Graphics::Point(x, y), sz, factory->Language()->GetString(2));
	y += sz.PosY() + s;

	GUI::Button* editor = factory->NewButton(Graphics::Point(x, y), sz, factory->Language()->GetString(3));
	y += sz.PosY() + s;

	GUI::Button* exit = factory->NewButton(Graphics::Point(x, y), sz, factory->Language()->GetString(4));
	y += sz.PosY() + s;

	this->Attach(newGame);
	this->Attach(settings);
	this->Attach(editor);
	this->Attach(exit);

	editor->Click = std::bind(&MainMenu::EditorOn, this);
	exit->Click = std::bind(&MainMenu::ExitOn, this);

	_Screen = images->GetImage("Images\\", "MainMenu.jpeg");
}

void MainMenu::Draw()
{
	Graphics::Point screenSize(this->Area().Width(), this->Area().Height());
	_Screen->Draw(Graphics::Point(0, 0), screenSize);

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}

void MainMenu::EditorOn()
{
	_Application->Activate(UI::UI::Editor);
}

void MainMenu::ExitOn()
{
	View()->StopEvent();
}