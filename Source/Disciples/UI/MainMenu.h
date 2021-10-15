#ifndef _Disciples_UI_MainMenu_h_
#define _Disciples_UI_MainMenu_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Managers/ImageManager.h"

namespace UI
{
	class MainMenu: public Arc::GUI::Form
	{
	public:
		MainMenu(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Managers::ImageManager* images);
		void Draw();
		void EditorOn(Arc::Graphics::Point pos);
		void ExitOn(Arc::Graphics::Point pos);
		void SettingsOn(Arc::Graphics::Point pos);
	private:
		Arc::GUI::Factory* _Factory;
		Arc::GUI::Application* _Application;
		Arc::Graphics::Image* _Screen;
	};
}

#endif