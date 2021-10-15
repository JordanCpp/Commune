#include "SpriteManager.h"

using namespace Fallout;

Managers::SpriteManager::SpriteManager(const std::string& path, Arc::Graphics::Canvas* canvas, Arc::Graphics::Color transparency):
	_ImageManager(path, canvas, transparency)
{
}

Fallout::Managers::SpriteManager::~SpriteManager()
{
	for (auto i = _Sprites.begin(); i != _Sprites.end(); i++)
	{
		delete i->second;
	}
}

Formats::Sprite* Managers::SpriteManager::Sprite(const std::string& dir, const std::string& file)
{
    auto i = _Sprites.find(_ImageManager.GetPath(dir, file));

    Formats::Sprite* p = nullptr;

    if (i == _Sprites.end())
    {
        p = new Formats::Sprite(_ImageManager.Canvas(), _ImageManager.GetPath(dir, file));
        _Sprites.emplace(_ImageManager.GetPath(dir, file), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}

Formats::Sprite* Managers::SpriteManager::Tile(const std::string& file)
{
    return Sprite("Art\\Tiles\\", file);
}

Formats::Sprite* Managers::SpriteManager::Critter(const std::string& file)
{
    return Sprite("Art\\Critters\\", file);
}