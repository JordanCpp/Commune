#ifndef _Arcturus_GUI_Button_h_
#define _Arcturus_GUI_Button_h_

#include "Widget.h"
#include "../Managers/TextManager.h"

namespace Arc
{
	namespace GUI
	{
		class Button : public Widget
		{
		public:
			Button(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption);
			void Draw();
		private:
			Managers::TextManager* _TextManager;
			std::string _Caption;
		};
	}
}

#endif