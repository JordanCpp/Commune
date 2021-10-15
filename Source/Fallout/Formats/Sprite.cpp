#include "Sprite.h"
#include "../Formats/FrmReader.h"

Fallout::Formats::Sprite::Sprite(Arc::Graphics::Canvas* canvas, const std::string& file):
	_Dirs(0),
	_Frames(0)
{
	Formats::FrmReader frm(file);

	_Dirs = frm.Dirs();
	_Frames = frm.Frames();

	Formats::FrmFrame frame;

	for (size_t i = 0; i < frm.Dirs(); i++)
	{
		for (size_t j = 0; j < frm.Frames(); j++)
		{
			frm.Next(frame);
			_Images[i][j] = new Arc::Graphics::Image(canvas, Arc::Graphics::Color(0, 0, 0), frame.width, frame.height, frame.pixels);
		}
	}
}

void Fallout::Formats::Sprite::Draw(size_t dir, size_t frame, Arc::Graphics::Point pos)
{
	_Images.at(dir).at(frame)->Draw(pos);
}

void Fallout::Formats::Sprite::Draw(size_t dir, Arc::Graphics::Point pos)
{
	Draw(dir, 0, pos);
}

void Fallout::Formats::Sprite::Draw(Arc::Graphics::Point pos)
{
	Draw(0, 0, pos);
}