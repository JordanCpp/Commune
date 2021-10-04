#include "MainMenu.h"
#include "UI.h"

using namespace UI;

MainMenu::MainMenu(GUI::Factory* factory, GUI::Application* application, Managers::ImageManager* images):
	GUI::Form(factory->View()),
	_Application(application)
{
	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Graphics::Point sz(200, 35);

	GUI::Button* button1 = factory->NewButton(Graphics::Point(x, y), sz, "New game");
	y += sz.PosY() + s;

	GUI::Button* button2 = factory->NewButton(Graphics::Point(x, y), sz, "Editor");
	y += sz.PosY() + s;

	GUI::Button* button3 = factory->NewButton(Graphics::Point(x, y), sz, "Exit");
	y += sz.PosY() + s;

	this->Attach(button1);
	this->Attach(button2);
	this->Attach(button3);

	button2->Click = std::bind(&MainMenu::EditorOn, this);

	

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