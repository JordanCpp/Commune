#ifndef _Arcturus_GUI_Form_h_
#define _Arcturus_GUI_Form_h_

#include "Widget.h"

namespace Arc
{
	namespace GUI
	{
		class Form : public Widget
		{
		public:
			Form(Graphics::Canvas* canvas);
			void Draw();
		private:
		};
	}
}

#endif