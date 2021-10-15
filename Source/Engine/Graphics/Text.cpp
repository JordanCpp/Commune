#include "Text.h"
#include <cassert>

using namespace Arc;
using namespace Graphics;

Text::Text(Canvas* CanvasSource, Font* FontSource, const std::string& TextSource):
    _Image(nullptr)
{
    SDL_Color color = { 0, 0, 0, 255 };

    SDL_Surface* surface = TTF_RenderUTF8_Blended(FontSource->Get(), TextSource.c_str(), color);
    assert(surface);

    _Image = new Image(CanvasSource, surface);

    //SDL_FreeSurface(surface);
}

Text::~Text()
{
    delete _Image;
}

int Text::Width()
{
    return _Image->Width();
}

int Text::Height()
{
    return _Image->Height();
}

void Text::Draw(Point Pt)
{
    _Image->Draw(Pt);
}