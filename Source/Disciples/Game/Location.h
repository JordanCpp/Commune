#ifndef _Disciples_Game_Location_h_
#define _Disciples_Game_Location_h_

#include <string>
#include <vector>
#include "../../Engine/Common/XmlReader.hpp"
#include "Tile.h"
#include "../../Engine/Managers/ImageManager.h"
#include "../../Engine/Graphics/Camera.h"
#include "Leader.h"
#include "../../Engine/Common/Isometric.h"

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
		Location(Arc::Graphics::Camera* CameraSource, Arc::Managers::ImageManager* ImageManagerSource);
		size_t Scale();
		void Scale(size_t percent);
		Arc::Graphics::Point Scale(size_t w, size_t h);
		size_t Width();
		size_t Height();
		size_t PointToIndex(Arc::Graphics::Point pt);
		Arc::Graphics::Point IndexToPoint(size_t index);
		Arc::Graphics::Point PosToIndex(Arc::Graphics::Point pos);
		void Draw();
	private:
		Arc::Graphics::Camera* _Camera;
		Arc::Managers::ImageManager* _ImageManager;
		size_t _Width;
		size_t _Height;
		std::vector<Tile> _Tiles;
		std::vector<Leader> _Leaders;
		size_t _Scaling;
		Arc::Common::Isometric _Isometric;
	};
}

#endif