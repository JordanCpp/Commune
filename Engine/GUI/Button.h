#ifndef _Engine_GUI2_Button_h_
#define _Engine_GUI2_Button_h_

#include "Widget.h"
#include "../Managers/TextManager.h"

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

#endif