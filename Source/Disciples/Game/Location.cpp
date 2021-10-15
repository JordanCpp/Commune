#include "Location.h"

using namespace Game;

Location::Location(Arc::Graphics::Camera* CameraSource, Arc::Managers::ImageManager* ImageManagerSource):
	_Camera(CameraSource),
	_ImageManager(ImageManagerSource),
	_Width(0),
	_Height(0),
	_Scaling(ScaleDefault)
{
}

size_t Game::Location::Scale()
{
	return _Scaling;
}

void Game::Location::Scale(size_t percent)
{
	if (percent >= 25)
	{
		_Scaling = percent;
	}
}

Arc::Graphics::Point Game::Location::Scale(size_t w, size_t h)
{
	size_t sw = size_t((float(w) / 100) * _Scaling);
	size_t sh = size_t((float(h) / 100) * _Scaling);

	return Arc::Graphics::Point(sw, sh);
}

size_t Location::Width()
{
	return 100;
}

size_t Location::Height()
{
	return 100;
}

size_t Location::PointToIndex(Arc::Graphics::Point pt)
{
	return (Width() * pt.PosY()) + pt.PosX();
}

Arc::Graphics::Point Location::IndexToPoint(size_t index)
{
	Arc::Graphics::Point pt(index % Width(), index / Width());

	return pt;
}

Arc::Graphics::Point Location::PosToIndex(Arc::Graphics::Point pos)
{
	float a = float((pos.PosX() - _Camera->PosX()) / Tile::DefaultWidth + (pos.PosY() - _Camera->PosY()) / Tile::DefaultHeight);
	float b = float((pos.PosY() - _Camera->PosY()) / Tile::DefaultHeight - (pos.PosX() - _Camera->PosX()) / Tile::DefaultWidth);

	return Arc::Graphics::Point((size_t)a, (size_t)b);
}

void Location::Draw()
{
	Arc::Graphics::Point scale = Scale(Tile::DefaultWidth, Tile::DefaultHeight);

	for (size_t rows = 0; rows < Width(); rows++)
	{
		for (size_t cols = 0; cols < Height(); cols++)
		{
			size_t x = cols * scale.PosX() / 2;
			size_t y = rows * scale.PosY();

			Arc::Graphics::Point pt = _Isometric.CartesianToIsometric(Arc::Graphics::Point(x, y));

			size_t dx = pt.PosX() + _Camera->PosX();
			size_t dy = pt.PosY() + _Camera->PosY();

			_ImageManager->GetImage("Images\\", "Default.png")->Draw(Arc::Graphics::Point(dx, dy), Arc::Graphics::Point(scale.PosX(), scale.PosY()));
		}
	}
}

/*
void Location::Draw()
{
	Graphics::Point scale = Scale(Tile::DefaultWidth, Tile::DefaultHeight);

	for (size_t k = 0; k < Width() * Height(); k++)
	{
		size_t i = k / Width();
		size_t j = k % Width();

		size_t x = j * scale.PosX() / 2;
		size_t y = i * scale.PosY();

		Graphics::Point pt = CartesianToIsometric(Graphics::Point(x, y));

		size_t dx = pt.PosX() + _Camera->PosX();
		size_t dy = pt.PosY() + _Camera->PosY();

		_ImageManager->GetImage("Images\\", "Default.png")->Draw(Graphics::Point(dx, dy), Graphics::Point(scale.PosX(), scale.PosY()));
	}
}
*/