#include "Editor.h"
 
using namespace UI;

Editor::Editor(GUI::Factory* factory, GUI::Application* application, Graphics::Camera* camera, Game::Location* location):
	Form(factory->View()),
	_Factory(factory),
	_Application(application),
	_Camera(camera),
	_Location(location)
{
	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Graphics::Point sz(35, 35);

	GUI::Button* scaleInc = factory->NewButton(Graphics::Point(x, y), sz, "+");
	GUI::Button* scaleDec = factory->NewButton(Graphics::Point(x + scaleInc->Area().Width() + s, y), sz, "-");

	this->Attach(scaleInc);
	this->Attach(scaleDec);

	this->Keyboard = std::bind(&Editor::KeyboardEvent, this, std::placeholders::_1);
	scaleInc->Click = std::bind(&Editor::ScaleInc, this);
	scaleDec->Click = std::bind(&Editor::ScaleDec, this);
	this->Click = std::bind(&Editor::ClickOn, this, std::placeholders::_1);
}

void Editor::Draw()
{
	_Location->Draw();

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		Widgets()[i]->Draw();
	}
}

void Editor::KeyboardEvent(size_t key)
{
	size_t step = Game::Tile::DefaultWidth * 5;

	if (key == SDLK_d)
		_Camera->PosX(_Camera->PosX() - step);

	if (key == SDLK_a)
		_Camera->PosX(_Camera->PosX() + step);

	if (key == SDLK_w)
		_Camera->PosY(_Camera->PosY() + step);

	if (key == SDLK_s)
		_Camera->PosY(_Camera->PosY() - step);

	if (key == SDLK_1)
		_Location->Scale(_Location->Scale() + 25);

	if (key == SDLK_2)
		_Location->Scale(_Location->Scale() - 25);

	if (key == SDLK_3)
		_Location->Scale(100);
}

void Editor::ScaleInc()
{
	_Location->Scale(_Location->Scale() + 25);
}

void Editor::ScaleDec()
{
	_Location->Scale(_Location->Scale() - 25);
}

void Editor::ClickOn(Graphics::Point pos)
{
	printf("pos: %d,%d\n", pos.PosX(), pos.PosY());

	Graphics::Point index(_Location->PosToIndex(pos));

	printf("index: %d,%d\n", index.PosX(), index.PosY());
	printf("Camera: %d,%d\n", _Camera->PosX(), _Camera->PosY());
}