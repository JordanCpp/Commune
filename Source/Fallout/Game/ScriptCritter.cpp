#include "ScriptCritter.h"

void Fallout::Game::ScriptCritter::Init(Critter* critter)
{
	_Critter = critter;
}

Fallout::Game::Critter* Fallout::Game::ScriptCritter::Self()
{
	return _Critter;
}