#include "Tile.h"

using namespace Fallout::Game;

void Tile::Init(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader)
{
    xmlReader->NextOpening("Tile");

    xmlReader->NextNode("View");

    _Body = spriteManager->Tile(xmlReader->Value());

    xmlReader->NextClosing("Tile");
}