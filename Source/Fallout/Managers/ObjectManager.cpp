#include "ObjectManager.h"

using namespace Fallout;
using namespace Managers;

ObjectManager::ObjectManager(const std::string& path, SpriteManager* spriteManager):
	_ProtoManager(path),
	_SpriteManager(spriteManager)
{
}

Game::Tile* ObjectManager::Tile(const std::string& protoFile)
{
	return new Game::Tile(_SpriteManager, _ProtoManager.Tile(protoFile));
}

Game::Critter* ObjectManager::Critter(const std::string& protoFile, const std::string& scriptFile)
{
	Game::Critter* critter = new Game::Critter(protoFile, &_ProtoManager);
	Game::ScriptCritter* script = _ScriptManager.Critter(scriptFile);

	critter->Init(script);
	script->Init(critter);

	return critter;
}