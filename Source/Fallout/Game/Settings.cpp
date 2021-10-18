#include "Settings.h"
#include "../../Engine/Common/XmlReader.hpp"
#include "..\..\Disciples\Game\Settings.h"

using namespace Fallout::Game;

Settings::Settings(const std::string& Name):
    size(Arc::Graphics::Point(0, 0)),
    fps(0)
{
    Arc::Common::XmlReader reader(Name);

    reader.NextOpening("Config");
    reader.NextOpening("Video");

    reader.NextNode("Title");
    title = reader.Value();

    reader.NextNode("Width");
    size.PosX(reader.ValueInt());

    reader.NextNode("Height");
    size.PosY(reader.ValueInt());

    reader.NextNode("Fps");
    fps = reader.ValueInt();

    reader.NextClosing("Video");
    
    reader.NextNode("Path");
    path = reader.Value();

    reader.NextOpening("Allocators");

    reader.NextNode("System");
    _SystemSize = reader.ValueInt();

    reader.NextNode("General");
    _GeneralSize = reader.ValueInt();

    reader.NextClosing("Allocators");

    reader.NextClosing("Config");
}

Settings::~Settings()
{
}

const std::string & Settings::Path()
{
    return path;
}

size_t Settings::Fps()
{
    return fps;
}

Arc::Graphics::Point Settings::WindowSize()
{
    return size;
}

const std::string& Settings::Title()
{
    return title;
}

size_t Settings::SystemSize()
{
    return _SystemSize;
}

size_t Settings::GeneralSize()
{
    return _GeneralSize;
}