#ifndef _Engine_GUI2_Form_h_
#define _Engine_GUI2_Form_h_

#include "Widget.h"

namespace GUI
{
	class Form: public Widget
	{
	public:
		Form(Graphics::Canvas* canvas);
		void Draw();
	private:
	};
}

#endif