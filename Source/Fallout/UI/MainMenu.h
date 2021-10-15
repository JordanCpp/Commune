#ifndef _Disciples_UI_MainMenu_h_
#define _Disciples_UI_MainMenu_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Managers/ImageManager.h"
#include "../Managers/SpriteManager.h"

namespace Fallout
{
	namespace UI
	{
		class MainMenu : public Arc::GUI::Form
		{
		public:
			MainMenu(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Managers::SpriteManager* _spriteManager);
			void Draw();
			void ExitOn(Arc::Graphics::Point pos);
		private:
			Arc::GUI::Factory* _Factory;
			Arc::GUI::Application* _Application;
			Managers::SpriteManager* _SpriteManager;
			Arc::Graphics::Image* _Img;
			Formats::Sprite* _Spr;
		};
	}
}

#endif