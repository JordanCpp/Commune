#ifndef _Managers_FontManager_h_
#define _Managers_FontManager_h_

#include "Manager.h"
#include <unordered_map>
#include "../Graphics/Font.h"

namespace Arc
{
	namespace Managers
	{
		class FontManager : public Manager
		{
		public:
			FontManager(const std::string& StartPath);
			~FontManager();
			Graphics::Font* GetFont(const std::string& DirName, const std::string& FileName);
		private:
			std::unordered_map<std::string, Graphics::Font*> _Fonts;
		};
	}
}

#endif