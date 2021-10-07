#ifndef _Disciples_UI_Editor_h_
#define _Disciples_UI_Editor_h_

#include "../../Engine/GUI/Factory.h"
#include "../../Engine/Graphics/Camera.h"
#include "../Game/Location.h"

namespace UI
{
	class Editor: public GUI::Form
	{
	public:
		Editor(GUI::Factory* factory, GUI::Application* application, Graphics::Camera* camera, Game::Location* location);
		void Draw();
		void KeyboardEvent(size_t key);
		void ScaleInc();
		void ScaleDec();
		void ScaleDef();
		void ClickOn(Graphics::Point pos);
	private:
		GUI::Factory* _Factory;
		GUI::Application* _Application;
		Graphics::Camera* _Camera;
		Game::Location* _Location;
	};
}

#endif