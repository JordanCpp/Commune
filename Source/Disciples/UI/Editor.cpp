#include "Editor.h"
#include "..\..\Fallout\UI\Editor.h"

using namespace UI;

Editor::Editor(Arc::GUI::Factory* factory, Arc::Managers::ImageManager* imageManager, Arc::GUI::Application* application, Arc::Graphics::Camera* camera, Game::Location* location):
	Form(factory->View()),
	_Factory(factory),
	_ImageManager(imageManager),
	_Application(application),
	_Camera(camera),
	_Location(location)
{
	size_t s = 5;
	size_t x = s;
	size_t y = s;
	Arc::Graphics::Point sz(50, 35);

	Arc::GUI::Button* scaleInc = factory->NewButton(Arc::Graphics::Point(x, y), sz, "+");
	x = x + sz.PosX() + s;

	Arc::GUI::Button* scaleDec = factory->NewButton(Arc::Graphics::Point(x, y), sz, "-");
	x = x + sz.PosX() + s;

	Arc::GUI::Button* scaleDef = factory->NewButton(Arc::Graphics::Point(x, y), sz, "100%");
	x = x + sz.PosX() + s;

	x = s;
	y = y + sz.PosY() + s;
	Arc::GUI::Button* select = factory->NewButton(Arc::Graphics::Point(x, y), sz, "N");

	win = factory->NewWindow(Arc::Graphics::Point(60, 55), Arc::Graphics::Point(640, 480));

	Arc::Graphics::Image* img = _ImageManager->GetImage("Images\\", "G000UU0007FACEB.PNG");
	Arc::GUI::Picture* pic = factory->NewPicture(Arc::Graphics::Point(60, 55), Arc::Graphics::Point(100, 100), img);

	this->Attach(scaleInc);
	this->Attach(scaleDec);
	this->Attach(scaleDef);
	this->Attach(select);
	this->Attach(win);

	win->Attach(pic);

	this->Keyboard = std::bind(&Editor::KeyboardEvent, this, std::placeholders::_1);
	scaleInc->Click = std::bind(&Editor::ScaleInc, this);
	scaleDec->Click = std::bind(&Editor::ScaleDec, this);
	scaleDef->Click = std::bind(&Editor::ScaleDef, this);
	select->Click = std::bind(&Editor::Select, this);
	this->Click = std::bind(&Editor::ClickOn, this, std::placeholders::_1);
}

void Editor::Draw()
{
	_Location->Draw();

	for (size_t i = 0; i < Widgets().size(); i++)
	{
		if (Widgets()[i]->Visible())
		{
			Widgets()[i]->Draw();
		}
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
}

void Editor::ScaleInc()
{
	_Location->Scale(_Location->Scale() + Game::Location::ScaleStep);
}

void Editor::ScaleDec()
{
	_Location->Scale(_Location->Scale() - Game::Location::ScaleStep);
}

void Editor::ScaleDef()
{
	_Location->Scale(Game::Location::ScaleDefault);
}

void Editor::Select()
{
	if (win->Visible())
		win->Off();
	else
		win->On();
}

void Editor::ClickOn(Arc::Graphics::Point pos)
{
	printf("pos: %d,%d\n", pos.PosX(), pos.PosY());

	Arc::Graphics::Point index(_Location->PosToIndex(pos));

	printf("indexes: %d,%d\n", index.PosX(), index.PosY());
	printf("Camera: %d,%d\n", _Camera->PosX(), _Camera->PosY());
	printf("index: %d\n", _Location->PointToIndex(index));
}