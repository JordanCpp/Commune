#include "Location.h"

using namespace Fallout;

Game::Location::Location(Managers::ObjectManager* objectManager):
	_ObjectManager(objectManager)
{
	for (size_t i = 0; i < 100 * 100; i++)
	{
		_Tiles[i] = _ObjectManager->Tile("Default.xml");
	}
}