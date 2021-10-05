#ifndef _Engine_GUI_Application_h_
#define _Engine_GUI_Application_h_

#include "Form.h"
#include <unordered_map>

namespace GUI
{
	class Application : public Widget
	{
	public:
		Application(Graphics::Canvas* CanvasSource);
		~Application();
		void Attach(size_t id, Form* form);
		void Activate(size_t id);
		void Handler(SDL_Event& report);
		void Draw();
	private:
		Widget* _Form;
		Widget* _Current;
		std::unordered_map<size_t, Form*> _Forms;
	};
}

#endif