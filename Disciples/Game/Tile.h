#ifndef _Disciples_Game_Tile_h_
#define _Disciples_Game_Tile_h_

#include "../../Engine/Graphics/Image.h"

namespace Game
{
	class Tile
	{
		enum
		{
			DefaultWidth = 64,
			DefaultHeight = 32
		};
	public:
		size_t Width();
		size_t Height();
	private:
		Graphics::Image _Body;
	};
}

#endif