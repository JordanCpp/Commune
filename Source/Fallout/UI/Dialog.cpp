#include "Dialog.h"

using namespace Fallout;

UI::Dialog::Dialog(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Managers::SpriteManager* spriteManager) :
	Arc::GUI::Form(factory->View()),
	_Factory(factory),
	_Application(application),
	_SpriteManager(spriteManager),
	_Script(nullptr)
{
}

void UI::Dialog::Init(ScriptCritter* script)
{
	_Script = script;
}

void UI::Dialog::Clear()
{
	_Options.clear();
}

void UI::Dialog::Reply(const std::string& text)
{
	_Reply = text;
}

void UI::Dialog::Option(const std::string& text, size_t node)
{
	_Option.Value.clear();
	
	_Option.Value  = text;
	_Option.Node   = node;

	_Options.push_back(_Option);
}