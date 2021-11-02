#ifndef _Fallout_UI_Dialog_h_
#define _Fallout_UI_Dialog_h_

#include "../../Engine/GUI/Factory.h"
#include "../Game/ScriptCritter.h"
#include "../Managers/SpriteManager.h"

class ScriptCritter;

namespace Fallout
{
	namespace UI
	{
		struct OptionValue
		{
			std::string Value;
			size_t Node;
		};

		class Dialog : public Arc::GUI::Form
		{
		public:
			Dialog(Arc::GUI::Factory* factory, Arc::GUI::Application* application, Managers::SpriteManager* spriteManager);
			void Init(ScriptCritter* script);
			void Clear();
			void Reply(const std::string& text);
			void Option(const std::string& text, size_t node);
		private:
			Arc::GUI::Factory* _Factory;
			Arc::GUI::Application* _Application;
			Managers::SpriteManager* _SpriteManager;
			ScriptCritter* _Script;
			std::string _Reply;
			std::vector<OptionValue> _Options;
			OptionValue _Option;
		};
	}
}

#endif