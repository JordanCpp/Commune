#include "ScriptCritter.h"

using namespace Fallout;

void Game::ScriptCritter::Talk(Dialog* dialog, size_t node)
{
}

void Game::ScriptCritter::Init(Game::Critter* critter)
{
	_Critter = critter;
}

Game::Critter* Game::ScriptCritter::Self()
{
	return _Critter;
}