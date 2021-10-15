#ifndef _Arcturus_GUI_Picture_h_
#define _Arcturus_GUI_Picture_h_

#include "Widget.h"
#include "../Graphics/Image.h"

namespace Arc
{
	namespace GUI
	{
		class Picture : public Widget
		{
		public:
			Picture(Graphics::Canvas* canvas, Graphics::Image* image, Graphics::Point pos, Graphics::Point size);
			void Draw();
		private:
			Graphics::Image* _Image;
		};
	}
}

#endif