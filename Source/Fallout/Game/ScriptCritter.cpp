#include "ScriptCritter.h"

using namespace Fallout::Game;

void ScriptCritter::Init(Critter* critter)
{
	_Critter = critter;
}

Critter* ScriptCritter::Self()
{
	return _Critter;
}