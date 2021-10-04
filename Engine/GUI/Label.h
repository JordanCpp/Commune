#ifndef _Engine_GUI2_Label_h_
#define _Engine_GUI2_Label_h_

#include "Widget.h"
#include "../Managers/TextManager.h"

namespace GUI
{
	class Label: public Widget
	{
	public:
		Label(Graphics::Canvas* CanvasSource, Managers::TextManager* TextManagerSource, Graphics::Point pos, Graphics::Point size, const std::string& caption);
		void Draw();
	private:
		Managers::TextManager* _TextManager;
		std::string _Caption;
	};
}

#endif