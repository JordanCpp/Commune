#include "MainMenu.h"
#include "UI.h"

using namespace Fallout::UI;

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

	GUI::Button* exit = factory->NewButton(Graphics::Point(x, y), sz, factory->Language()->GetString(4));
	y += sz.PosY() + s;

	this->Attach(exit);

	exit->Click = std::bind(&MainMenu::ExitOn, this, std::placeholders::_1);
}

void MainMenu::Draw()
{
	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}

void MainMenu::ExitOn(Graphics::Point pos)
{
	View()->StopEvent();
}