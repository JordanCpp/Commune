#include "TextureManager.h"

using namespace Arc;
using namespace Managers;

TextureManager::TextureManager(const std::string& path):
	_Manager(path)
{
}

Graphics::Texture2D* TextureManager::GetTexture2D(const std::string& dir, const std::string& file)
{
    auto i = _Textures2D.find(_Manager.GetPath(dir, file));

    Graphics::Texture2D* p = nullptr;

    if (i == _Textures2D.end())
    {
        p = new Graphics::Texture2D(_Manager.GetPath(dir, file));
        _Textures2D.emplace(_Manager.GetPath(dir, file), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}