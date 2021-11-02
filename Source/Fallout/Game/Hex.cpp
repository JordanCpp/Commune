#include "Hex.h"

using namespace Fallout;

Game::Hex::Hex(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader)
{
    xmlReader->NextOpening("Tile");

    xmlReader->NextNode("View");

    _Body = spriteManager->Tile(xmlReader->Value());

    xmlReader->NextClosing("Tile");
}

void Game::Hex::Draw(Arc::Graphics::Point pos)
{
    _Body->Draw(pos);
}