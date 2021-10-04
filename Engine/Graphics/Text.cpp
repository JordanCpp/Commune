#include "Text.h"
#include <cassert>

Graphics::Text::Text(Graphics::Canvas* CanvasSource, Graphics::Font* FontSource, const std::string& TextSource):
    _Image(nullptr)
{
    SDL_Color color = { 0, 0, 0, 255 };

    SDL_Surface* surface = TTF_RenderUTF8_Blended(FontSource->Get(), TextSource.c_str(), color);
    assert(surface);

    _Image = new Image(CanvasSource, surface);

    //SDL_FreeSurface(surface);
}

Graphics::Text::~Text()
{
    delete _Image;
}

int Graphics::Text::Width()
{
    return _Image->Width();
}

int Graphics::Text::Height()
{
    return _Image->Height();
}

void Graphics::Text::Draw(Point Pt)
{
    _Image->Draw(Pt);
}