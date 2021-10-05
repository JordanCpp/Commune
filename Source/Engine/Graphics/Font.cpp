#include "Font.h"
#include <cassert>

Graphics::Font::Font(const std::string& FileName):
	_Font(nullptr)
{
	_Font = TTF_OpenFont(FileName.c_str(), 12);
	assert(_Font != nullptr);

}

Graphics::Font::~Font()
{
	TTF_CloseFont(_Font);
}

TTF_Font* Graphics::Font::Get()
{
	return _Font;
}