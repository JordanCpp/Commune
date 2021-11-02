#include "ObjectManager.h"
#include <cassert>

using namespace Fallout;
using namespace Managers;

ObjectManager::ObjectManager(const std::string& path, Arc::Allocators::Allocator* allocator, SpriteManager* spriteManager):
	_Allocator(allocator),
	_ProtoManager(path),
	_SpriteManager(spriteManager)
{
}

Game::Tile* ObjectManager::Tile(const std::string& protoFile)
{
	Game::Tile* tile = new(_Allocator->Alloc(sizeof(Game::Tile))) Game::Tile(_SpriteManager, _ProtoManager.Tile(protoFile));

	return tile;
}

Game::Hex* ObjectManager::Hex(const std::string& protoFile)
{
	Game::Hex* hex = new (_Allocator->Alloc(sizeof(Game::Hex))) Game::Hex(_SpriteManager, _ProtoManager.Tile(protoFile));

	return hex;
}

Game::Critter* ObjectManager::Critter(const std::string& protoFile, const std::string& scriptFile)
{
	Game::Critter* critter = new (_Allocator->Alloc(sizeof(Game::Critter))) Game::Critter(protoFile, &_ProtoManager);
	Game::ScriptCritter* script = _ScriptManager.Critter(scriptFile);

	critter->Init(script);
	script->Init(critter);

	return critter;
}