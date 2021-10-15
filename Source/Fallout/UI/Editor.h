#ifndef _Fallout_UI_Editor_h_
#define _Fallout_UI_Editor_h_

#include "../../Engine/GUI/Factory.h"

namespace Fallout
{
	namespace UI
	{
		class Editor : public Arc::GUI::Form
		{
		public:
			Editor(Arc::GUI::Factory* factory, Arc::GUI::Application* application);
		private:
			Arc::GUI::Factory* _Factory;
			Arc::GUI::Application* _Application;
		};
	}
}

#endif