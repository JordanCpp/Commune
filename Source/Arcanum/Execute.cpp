#include "Execute.h"
#include <SDL2/SDL_opengl.h>

using namespace Arcanum;

Execute::Execute(const std::string& path):
	_Canvas(Arc::Graphics::Point(1366, 768), 60)
{
}

void Execute::Run()
{
	SDL_Event report = { 0 };

	while (_Canvas.GetEvent(report))
	{
		glViewport(0, 0, _Canvas.Width(), _Canvas.Height());
		glClearColor(1.f, 0.f, 1.f, 0.f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}