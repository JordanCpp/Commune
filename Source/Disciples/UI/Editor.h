#ifndef _Disciples_UI_Editor_h_
#define _Disciples_UI_Editor_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Graphics/Camera.h"
#include "../Game/Location.h"

namespace UI
{
	class Editor: public Arc::GUI::Form
	{
	public:
		Editor(Arc::GUI::Factory* factory, Arc::Managers::ImageManager* imageManager, Arc::GUI::Application* application, Arc::Graphics::Camera* camera, Game::Location* location);
		void Draw();
		void KeyboardEvent(size_t key);
		void ScaleInc();
		void ScaleDec();
		void ScaleDef();
		void Select();
		void ClickOn(Arc::Graphics::Point pos);
	private:
		Arc::GUI::Factory* _Factory;
		Arc::Managers::ImageManager* _ImageManager;
		Arc::GUI::Application* _Application;
		Arc::Graphics::Camera* _Camera;
		Game::Location* _Location;
		Arc::GUI::Window* win;
	};
}

#endif