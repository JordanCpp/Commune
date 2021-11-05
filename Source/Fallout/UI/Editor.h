#ifndef _Fallout_UI_Editor_h_
#define _Fallout_UI_Editor_h_

#include "../../Engine/GUI/Factory.h"
#include "../Managers/SpriteManager.h"
#include "../Managers/ObjectManager.h"
#include "../Game/Location.h"
#include "../../Engine/Graphics/Camera.h"

namespace Fallout
{
	namespace UI
	{
		class Editor : public Arc::GUI::Form
		{
		public:
			Editor(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Arc::Graphics::Camera* camera, Managers::SpriteManager* spriteManager, Managers::ObjectManager* objectManager);
			void KeyboardEvent(size_t key);
			void Draw();
			void ClickOn(Arc::Graphics::Point pos);
		private:
			Arc::GUI::Factory* _Factory;
			Arc::GUI::Application* _Application;
			Arc::Graphics::Camera* _Camera;
			Managers::SpriteManager* _SpriteManager;
			Managers::ObjectManager* _ObjectManager;
			Game::Location _Location;
		};
	}
}

#endif