#include <cassert>
#include "ScriptManager.h"
#include "../Scripts/Tester.h"

using namespace Fallout;

Managers::ScriptManager::ScriptManager()
{
}

Managers::ScriptManager::~ScriptManager()
{
    for (size_t i = 0; i < _Scripts.size(); i++)
    {
        delete _Scripts.at(i);
    }
}

Game::ScriptCritter* Managers::ScriptManager::Critter(const std::string& file)
{
    Game::ScriptCritter* result = nullptr;

    if (file == "Tester")
    {
        result = new Game::Tester();
    }

    assert(result);

    _Scripts.at(_Scripts.size() + 1) = result;

    return result;
}