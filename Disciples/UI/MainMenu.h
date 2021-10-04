#ifndef _Disciples_UI_MainMenu_h_
#define _Disciples_UI_MainMenu_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Managers/ImageManager.h"

namespace UI
{
	class MainMenu: public GUI::Form
	{
	public:
		MainMenu(GUI::Factory* factory, GUI::Application* application, Managers::ImageManager* images);
		void Draw();
		void EditorOn();
	private:
		GUI::Application* _Application;
		Graphics::Image* _Screen;
	};
}

#endif