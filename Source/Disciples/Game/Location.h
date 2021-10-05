#ifndef _Disciples_Game_Location_h_
#define _Disciples_Game_Location_h_

#include <string>
#include <vector>
#include "../../Engine/Common/XmlReader.hpp"
#include "Tile.h"
#include "../../Engine/Managers/ImageManager.h"
#include "../../Engine/Graphics/Camera.h"
#include "Leader.h"

namespace Game
{
	class Location
	{
	public:
		enum
		{
			ScaleMin = 25,
			ScaleMax = 300,
			ScaleStep = 25,
			ScaleDefault = 100
		};
		Location(Graphics::Camera* CameraSource, Managers::ImageManager* ImageManagerSource);
		size_t Scale();
		void Scale(size_t percent);
		Graphics::Point Scale(size_t w, size_t h);
		size_t Width();
		size_t Height();
		Graphics::Point CartesianToIsometric(Graphics::Point pt);
		Graphics::Point IsometricToCartesian(Graphics::Point pt);
		size_t PointToIndex(Graphics::Point pt);
		Graphics::Point IndexToPoint(size_t index);
		Graphics::Point PosToIndex(Graphics::Point pos);
		void Draw();
	private:
		Graphics::Camera* _Camera;
		Managers::ImageManager* _ImageManager;
		size_t _Width;
		size_t _Height;
		std::vector<Tile> _Tiles;
		std::vector<Leader> _Leaders;
		size_t _Scaling;
	};
}

#endif