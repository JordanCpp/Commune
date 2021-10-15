#ifndef _Fallout_Formats_Sprite_h_
#define _Fallout_Formats_Sprite_h_

#include "../../Engine/Graphics/Image.h"
#include <array>

namespace Fallout
{
	namespace Formats
	{
		class Sprite
		{
		public:
			enum
			{
				MaxDirs = 6,
				MaxFarames = 32
			};
			Sprite(Arc::Graphics::Canvas* canvas, const std::string& file);
			void Draw(size_t dir, size_t frame, Arc::Graphics::Point pos);
			void Draw(size_t dir, Arc::Graphics::Point pos);
			void Draw(Arc::Graphics::Point pos);
		private:
			std::array<std::array<Arc::Graphics::Image*, MaxFarames>, MaxDirs> _Images;
		};
	}
}

#endif