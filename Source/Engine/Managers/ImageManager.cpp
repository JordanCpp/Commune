#include "ImageManager.h"

using namespace Arc;
using namespace Managers;

ImageManager::ImageManager(const std::string& StartPath, Graphics::Canvas* CanvasSource, Graphics::Color transparencySource):
	_Canvas(CanvasSource),
    _Transparency(transparencySource),
	Manager(StartPath)
{
}

ImageManager::~ImageManager()
{
	for (auto i = images.begin(); i != images.end(); i++)
	{
		delete i->second;
	}
}

Graphics::Canvas* ImageManager::Canvas()
{
    return _Canvas;
}

Graphics::Color Managers::ImageManager::Transparency()
{
    return _Transparency;
}

Graphics::Image* ImageManager::GetImage(const std::string& DirName, const std::string& FileName)
{
    auto i = images.find(GetPath(DirName, FileName));

    Graphics::Image* p = nullptr;

    if (i == images.end())
    {
        p = new Graphics::Image(_Canvas, Transparency(), GetPath(DirName, FileName));
        images.emplace(GetPath(DirName, FileName), p);
    }
    else
    {
        p = i->second;
    }

    return p;
}