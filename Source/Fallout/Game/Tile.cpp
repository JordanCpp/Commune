#include "Tile.h"

using namespace Fallout;

Game::Tile::Tile(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader):
    _Body(nullptr)
{
    xmlReader->NextOpening("Tile");

    xmlReader->NextNode("View");

    _Body = spriteManager->Tile(xmlReader->Value());

    xmlReader->NextClosing("Tile");
}