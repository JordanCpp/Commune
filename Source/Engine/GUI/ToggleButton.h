#ifndef _Arcturus_GUI_ToggleButton_h_
#define _Arcturus_GUI_ToggleButton_h_

#include "Widget.h"
#include "../Managers/TextManager.h"

namespace Arc
{
	namespace GUI
	{
		class ToggleButton: public Widget
		{
		public:
			enum
			{
				On,
				Off
			};
			ToggleButton(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption);
			void Draw();
		private:
			size_t _State;
			Managers::TextManager* _TextManager;
			std::string _Caption;
		};
	}
}

#endif