#include "Tile.h"

using namespace Fallout;

Game::Tile::Tile(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader)
{
    xmlReader->NextOpening("Tile");

    xmlReader->NextNode("View");

    _Body = spriteManager->Tile(xmlReader->Value());

    xmlReader->NextClosing("Tile");
}

void Game::Tile::Draw(Arc::Graphics::Point pos)
{
    _Body->Draw(pos);
}