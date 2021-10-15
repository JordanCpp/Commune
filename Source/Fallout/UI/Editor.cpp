#include "Editor.h"

Fallout::UI::Editor::Editor(Arc::GUI::Factory* factory, Arc::GUI::Application* application):
	Arc::GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application)
{
}