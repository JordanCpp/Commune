#include "Editor.h"

using namespace Fallout;

UI::Editor::Editor(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Graphics::Camera* camera, Managers::SpriteManager* spriteManager, Managers::ObjectManager* objectManager):
	Arc::GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application),
	_Camera(camera),
	_SpriteManager(spriteManager),
	_Location(camera, objectManager)
{

	this->Keyboard = std::bind(&Editor::KeyboardEvent, this, std::placeholders::_1);
}

void UI::Editor::KeyboardEvent(size_t key)
{
	size_t step = Game::Tile::Width * 3;

	if (key == SDLK_d)
		_Camera->PosX(_Camera->PosX() - step);

	if (key == SDLK_a)
		_Camera->PosX(_Camera->PosX() + step);

	if (key == SDLK_w)
		_Camera->PosY(_Camera->PosY() + step);

	if (key == SDLK_s)
		_Camera->PosY(_Camera->PosY() - step);
}

void UI::Editor::Draw()
{
	_Location.Draw();
}