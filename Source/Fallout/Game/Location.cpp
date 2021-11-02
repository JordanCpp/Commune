#include "Location.h"

using namespace Fallout;

Game::Location::Location(Arc::Graphics::Camera* camera, Managers::ObjectManager* objectManager):
	_Camera(camera),
	_ObjectManager(objectManager),
	_Size(300)
{
	for (size_t i = 0; i < Size() * Size(); i++)
	{
		_Tiles[i] = _ObjectManager->Tile("cav4017.xml");
	}

	for (size_t i = 0; i < Size() * Size() * 4; i++)
	{
		_Hexes[i] = _ObjectManager->Hex("Default.xml");
	}
}

size_t Game::Location::Size()
{
	return _Size;
}

int Game::Location::IndexToPosX(int t)
{
	int tx = t % Size();
	int ty = t / Size();

	return (2 * Game::Tile::RatioX * ty) - (3 * Game::Tile::RatioX * tx);
}

int Game::Location::IndexToPosY(int t)
{
	int tx = t % Size();
	int ty = t / Size();

	return (2 * Game::Tile::RatioY * ty) + (Game::Tile::RatioY * tx);
}

int Game::Location::HexToPosX(int t)
{
	int tx = t % (Size() * 2);
	int ty = t / (Size() * 2);

	return Game::Tile::RatioX * (ty - tx - tx / 2) - 8;
}

int Game::Location::HexToPosY(int t)
{
	int tx = t % (Size() * 2);
	int ty = t / (Size() * 2);

	return Game::Tile::RatioY * (ty + tx - tx / 2) - 32;
}

void Game::Location::Hexes()
{
	for (size_t i = 0; i < Size() * Size() * 4; i++)
	{
		int x = HexToPosX(i) + _Camera->PosX();
		int y = HexToPosY(i) + _Camera->PosY();

		_Hexes[i]->Draw(Arc::Graphics::Point(x, y));
	}
}

void Game::Location::Tiles()
{
	for (size_t i = 0; i < Size() * Size(); i++)
	{
		_Tiles[i]->Draw(Arc::Graphics::Point(IndexToPosX(i) + _Camera->PosX(), IndexToPosY(i) + _Camera->PosY()));
	}
}

void Game::Location::Draw()
{
	Tiles();
	//Hexes();
}