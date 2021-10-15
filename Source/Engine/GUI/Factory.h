#ifndef _Engine_GUI_Factory_h_
#define _Engine_GUI_Factory_h_

#include "../../Engine/Managers/LanguageManager.h"
#include "Application.h"
#include "Form.h"
#include "Button.h"
#include "Label.h"
#include "Window.h"
#include "Picture.h"

namespace Arc
{
	namespace GUI
	{
		class Factory
		{
		public:
			Factory(Graphics::Canvas* canvas, Managers::TextManager* text, Managers::LanguageManager* language);
			~Factory();
			Graphics::Canvas* View();
			Managers::TextManager* Text();
			Managers::LanguageManager* Language();
			Application* NewApplication();
			Form* NewForm();
			Button* NewButton(Graphics::Point pos, Graphics::Point size, const std::string& caption);
			Label* NewLabel(Graphics::Point pos, Graphics::Point size, const std::string& caption);
			Window* NewWindow(Graphics::Point pos, Graphics::Point size);
			Picture* NewPicture(Graphics::Point pos, Graphics::Point size, Graphics::Image* image);
		private:
			Graphics::Canvas* _Canvas;
			Managers::TextManager* _TextManager;
			Managers::LanguageManager* _LanguageManager;
			std::vector<Widget*> _Widgets;
		};
	}
}

#endif