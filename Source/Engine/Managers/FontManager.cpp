#include "FontManager.h"

using namespace Managers;

FontManager::FontManager(const std::string& StartPath):
	Manager(StartPath)
{
}

Managers::FontManager::~FontManager()
{
    for (auto i = _Fonts.begin(); i != _Fonts.end(); i++)
    {
        delete i->second;
    }
}

Graphics::Font* Managers::FontManager::GetFont(const std::string& DirName, const std::string& FileName)
{
    auto i = _Fonts.find(GetPath(DirName, FileName));

    Graphics::Font* p = nullptr;

    if (i == _Fonts.end())
    {
        p = new Graphics::Font(GetPath(DirName, FileName));
        _Fonts.emplace(GetPath(DirName, FileName), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}