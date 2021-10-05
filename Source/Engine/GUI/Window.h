#ifndef _Engine_GUI_Window_h_
#define _Engine_GUI_Window_h_

#include "Widget.h"
#include "../Managers/TextManager.h"

namespace GUI
{
	class Window: public Widget
	{
	public:
		Window(Graphics::Canvas* canvas, Managers::TextManager* text, Graphics::Point pos, Graphics::Point size);
		void Draw();
	private:
		Managers::TextManager* _TextManager;
	};
}

#endif
