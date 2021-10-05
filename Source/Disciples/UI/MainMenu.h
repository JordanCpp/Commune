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
		void EditorOn(Graphics::Point pos);
		void ExitOn(Graphics::Point pos);
		void SettingsOn(Graphics::Point pos);
	private:
		GUI::Factory* _Factory;
		GUI::Application* _Application;
		Graphics::Image* _Screen;
	};
}

#endif