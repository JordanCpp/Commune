#include "Settings.h"
#include "../../Engine/Common/XmlReader.hpp"

using namespace Game;

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