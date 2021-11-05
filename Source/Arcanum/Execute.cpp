#include "Execute.h"

namespace GL
{
#include <SDL2/SDL_opengl.h>
}

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
		GL::glViewport(0, 0, _Canvas.Width(), _Canvas.Height());
		GL::glClearColor(1.f, 0.f, 1.f, 0.f);
		GL::glClear(GL_COLOR_BUFFER_BIT);
	}
}