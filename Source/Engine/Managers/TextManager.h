#ifndef _Arcturus_Managers_TextManager_h_
#define _Arcturus_Managers_TextManager_h_

#include "FontManager.h"
#include "../Graphics/Canvas.h"
#include <unordered_map>
#include "../Graphics/Text.h"

namespace Arc
{
	namespace Managers
	{
		class TextManager
		{
		public:
			TextManager(Graphics::Canvas* CanvasSource, FontManager* FontManagerSource);
			~TextManager();
			void Activate(const std::string& FontName);
			Graphics::Text* GetText(const std::string& TextSource);
		private:
			Graphics::Canvas* _Canvas;
			FontManager* _FontManager;
			Graphics::Font* _Current;
			std::unordered_map<std::string, Graphics::Text*> _Texts;
		};
	}
}

#endif