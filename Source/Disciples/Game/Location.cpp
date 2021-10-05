#include "Location.h"

using namespace Game;

Location::Location(Graphics::Camera* CameraSource, Managers::ImageManager* ImageManagerSource):
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

Graphics::Point Game::Location::Scale(size_t w, size_t h)
{
	size_t sw = (float(w) / 100) * _Scaling;
	size_t sh = (float(h) / 100) * _Scaling;

	return Graphics::Point(sw, sh);
}

size_t Location::Width()
{
	return 100;
}

size_t Location::Height()
{
	return 100;
}

Graphics::Point Location::CartesianToIsometric(Graphics::Point pt)
{
	size_t x = pt.PosX() - pt.PosY();
	size_t y = (pt.PosX() + pt.PosY()) / 2;

	return Graphics::Point(x, y);
}

Graphics::Point Location::IsometricToCartesian(Graphics::Point pt)
{
	size_t x = (2 * pt.PosY() + pt.PosX()) / 2;
	size_t y = (2 * pt.PosY() - pt.PosX()) / 2;

	return Graphics::Point(x, y);
}

size_t Location::PointToIndex(Graphics::Point pt)
{
	return (Width() * pt.PosY()) + pt.PosX();
}

Graphics::Point Location::IndexToPoint(size_t index)
{
	Graphics::Point pt(index % Width(), index / Width());

	return pt;
}

Graphics::Point Location::PosToIndex(Graphics::Point pos)
{
	size_t a = (pos.PosX() - _Camera->PosX()) / Tile::DefaultWidth + (pos.PosY() - _Camera->PosY()) / Tile::DefaultHeight;
	size_t b = (pos.PosY() - _Camera->PosY()) / Tile::DefaultHeight - (pos.PosX() - _Camera->PosX()) / Tile::DefaultWidth;

	return Graphics::Point(a, b);
}

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