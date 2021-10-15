#include "Critter.h"

Fallout::Game::Critter::Critter(Arc::Common::XmlReader* xmlReader):
	_Script(nullptr)
{
    xmlReader->NextOpening("Critter");
    xmlReader->NextClosing("Critter");
}

void Fallout::Game::Critter::Init(ScriptCritter* script)
{
	_Script = script;
}

Fallout::Game::ScriptCritter* Fallout::Game::Critter::Self()
{
	return _Script;
}