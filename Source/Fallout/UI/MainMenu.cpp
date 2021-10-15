#include "MainMenu.h"
#include "UI.h"
#include "../Formats/FrmReader.h"

using namespace Fallout::UI;

MainMenu::MainMenu(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Managers::ImageManager* imageManager):
	Arc::GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application),
	_ImageManager(imageManager)
{
	factory->Language()->ActivateLang("Russian");
	factory->Language()->ActivateFile("Game");

	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Arc::Graphics::Point sz(200, 35);

	Arc::GUI::Button* exit = factory->NewButton(Arc::Graphics::Point(x, y), sz, factory->Language()->GetString(4));
	y += sz.PosY() + s;

	this->Attach(exit);

	exit->Click = std::bind(&MainMenu::ExitOn, this, std::placeholders::_1);

	_Spr = new Formats::Sprite(factory->View(), "D:\\HANPWRAA.FRM");
}

void MainMenu::Draw()
{
	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}

	_Spr->Draw(0, 0, Arc::Graphics::Point(100, 100));
}

void MainMenu::ExitOn(Arc::Graphics::Point pos)
{
	View()->StopEvent();
}