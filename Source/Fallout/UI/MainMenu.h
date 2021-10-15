#ifndef _Disciples_UI_MainMenu_h_
#define _Disciples_UI_MainMenu_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Managers/ImageManager.h"

namespace Fallout
{
	namespace UI
	{
		class MainMenu : public Arc::GUI::Form
		{
		public:
			MainMenu(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Managers::ImageManager* imageManager);
			void Draw();
			void ExitOn(Arc::Graphics::Point pos);
		private:
			Arc::GUI::Factory* _Factory;
			Arc::GUI::Application* _Application;
			Arc::Managers::ImageManager* _ImageManager;
		};
	}
}

#endif