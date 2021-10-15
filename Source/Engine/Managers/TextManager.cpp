#include "TextManager.h"
#include <cassert>

using namespace Arc;

Managers::TextManager::TextManager(Graphics::Canvas* CanvasSource, FontManager* FontManagerSource):
	_Canvas(CanvasSource),
	_FontManager(FontManagerSource),
    _Current(nullptr)
{
}

Managers::TextManager::~TextManager()
{
    for (auto i = _Texts.begin(); i != _Texts.end(); i++)
    {
        delete i->second;
    }
}

void Managers::TextManager::Activate(const std::string& FontName)
{
    _Current = _FontManager->GetFont("Fonts\\", FontName);
}

Graphics::Text* Managers::TextManager::GetText(const std::string& TextSource)
{
    auto i = _Texts.find(TextSource);

    Graphics::Text* p = nullptr;

    if (i == _Texts.end())
    {
        assert(_Current);
        p = new Graphics::Text(_Canvas, _Current, TextSource);
        _Texts.emplace(TextSource, p);
    }
    else
    {
        p = i->second;
    }

    return p;
}