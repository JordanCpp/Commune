#ifndef _Arcturus_Graphics_Camera_h_
#define _Arcturus_Graphics_Camera_h_

#include "Point.h"

namespace Arc
{
	namespace Graphics
	{
		class Camera
		{
		public:
			Camera(Graphics::Point pos, Graphics::Point size);
			size_t PosX();
			size_t PosY();
			size_t Width();
			size_t Height();
			void PosX(size_t value);
			void PosY(size_t value);
			void Width(size_t value);
			void Height(size_t value);
		private:
			Graphics::Point _Pos;
			Graphics::Point _Size;
		};
	}
}

#endif