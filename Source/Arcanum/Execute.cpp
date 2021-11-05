#include "Execute.h"

namespace GL
{
#include <SDL2/SDL_opengl.h>
}

using namespace Arcanum;

Execute::Execute(const std::string& path):
	_Canvas(Arc::Graphics::Point(1366, 768), 9999)
{
}

void Execute::Run()
{
	SDL_Event report = { 0 };

	GL::glViewport(0, 0, _Canvas.Width(), _Canvas.Height());

	while (_Canvas.GetEvent(report))
	{
		GL::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);							
		GL::glLoadIdentity();

		GL::glBegin(GL_TRIANGLES);
		GL::glVertex3f(0.0f, 1.0f, 0.0f);
		GL::glVertex3f(-1.0f, -1.0f, 0.0f);
		GL::glVertex3f(1.0f, -1.0f, 0.0f);
		GL::glEnd();
	}
}