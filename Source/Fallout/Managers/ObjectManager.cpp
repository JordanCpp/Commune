#include "ObjectManager.h"

using namespace Fallout;
using namespace Managers;

ObjectManager::ObjectManager(const std::string& path, SpriteManager* spriteManager):
	_ProtoManager(path),
	_SpriteManager(spriteManager)
{
}

Game::Tile* ObjectManager::Tile(const std::string& file)
{
	return new Game::Tile(_SpriteManager, _ProtoManager.Tile(file));
}

Game::Critter* ObjectManager::Critter(const std::string& proto, const std::string& script)
{
	Game::Critter* obj = new Game::Critter(_ProtoManager.Critter(proto));

	return obj;
}