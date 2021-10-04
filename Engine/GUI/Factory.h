#ifndef _Engine_GUI2_Factory_h_
#define _Engine_GUI2_Factory_h_

#include "../../Engine/Graphics/Canvas.h"
#include "../Managers/TextManager.h"
#include "Application.h"
#include "Form.h"
#include "Button.h"
#include "Label.h"

namespace GUI
{
	class Factory
	{
	public:
		Factory(Graphics::Canvas* canvas, Managers::TextManager* text);
		~Factory();
		Graphics::Canvas* View();
		Managers::TextManager* Text();
		Application* NewApplication();
		Form* NewForm();
		Button* NewButton(Graphics::Point pos, Graphics::Point size, const std::string& caption);
		Label* NewLabel(Graphics::Point pos, Graphics::Point size, const std::string& caption);
	private:
		Graphics::Canvas* _Canvas;
		Managers::TextManager* _TextManager;
		std::vector<Widget*> _Widgets;
	};
}

#endif