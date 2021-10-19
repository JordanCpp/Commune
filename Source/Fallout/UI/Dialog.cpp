#include "Dialog.h"

using namespace Fallout;

UI::Dialog::Dialog(ScriptCritter* script):
	_Script(script)
{
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