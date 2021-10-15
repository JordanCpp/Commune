#ifndef _Engine_Graphics_Font_h_
#define _Engine_Graphics_Font_h_

#include <string>
#include <SDL2/SDL_ttf.h>

namespace Arc
{
	namespace Graphics
	{
		class Font
		{
		public:
			Font(const std::string& FileName);
			~Font();
			TTF_Font* Get();
		private:
			TTF_Font* _Font;
		};
	}
}

#endif