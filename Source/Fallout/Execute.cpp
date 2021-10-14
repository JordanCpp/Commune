#include "Execute.h"

using namespace Fallout;

Execute::Execute(const std::string& path):
	_Settings(path),
	_Canvas(_Settings.WindowSize(), _Settings.Fps(), _Settings.Title()),
	_Camera(Graphics::Point(0, 0), Graphics::Point(_Canvas.Width(), _Canvas.Height()))
{
}

void Execute::Run()
{
	SDL_Event report = { 0 };

	while (_Canvas.GetEvent(report))
	{
	}
}