#include "ObjectManager.h"
#include <cassert>

using namespace Fallout;
using namespace Managers;

ObjectManager::ObjectManager(const std::string& path, SpriteManager* spriteManager):
	_ProtoManager(path),
	_SpriteManager(spriteManager),
	_TileIndex(0),
	_CritterIndex(0)
{
}

Game::Tile* ObjectManager::Tile(const std::string& protoFile)
{
	assert(_TileIndex < Limits::MaxTiles);

	Game::Tile* tile = new (&_Tiles[_TileIndex]) Game::Tile();
	_TileIndex++;

	tile->Init(_SpriteManager, _ProtoManager.Tile(protoFile));

	return tile;
}

Game::Critter* ObjectManager::Critter(const std::string& protoFile, const std::string& scriptFile)
{
	assert(_CritterIndex < Limits::MaxCritters);

	Game::Critter* critter = new(&_Tiles[_CritterIndex]) Game::Critter();
	critter->Init(protoFile, &_ProtoManager);
	_CritterIndex++;

	Game::ScriptCritter* script = _ScriptManager.Critter(scriptFile);

	critter->Init(script);
	script->Init(critter);

	return critter;
}