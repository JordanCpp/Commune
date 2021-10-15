#include "Tile.h"
#include "..\..\Fallout\Game\Tile.h"

using namespace Game;

size_t Tile::Width()
{
	return DefaultWidth;
}

size_t Tile::Height()
{
	return DefaultHeight;
}

Fallout::Game::Tile::Tile(Arc::Common::XmlReader* reader)
{
}