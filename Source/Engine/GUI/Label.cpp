#include "Label.h"

using namespace Arc;
using namespace GUI;

Label::Label(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption) :
	Widget(CanvasSource, pos, size),
	_TextManager(TextManagerSource),
	_Caption(caption)
{
}

void Label::Draw()
{
	Graphics::Text* text = _TextManager->GetText(_Caption);
	size_t x = Area().PosX() + (Area().Width() / 2 - text->Width() / 2);
	size_t y = Area().PosY() + (Area().Height() / 2 - text->Height() / 2);
	text->Draw(Graphics::Point(x, y));
}