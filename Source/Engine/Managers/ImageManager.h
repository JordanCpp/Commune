#ifndef _Arcturus_Managers_ImageManager_h_
#define _Arcturus_Managers_ImageManager_h_

#include <unordered_map>
#include "Manager.h"
#include "../Graphics/Image.h"

namespace Arc
{
	namespace Managers
	{
		class ImageManager : public Manager
		{
		public:
			ImageManager(const std::string& StartPath, Graphics::Canvas* CanvasSource, Graphics::Color transparencySource);
			~ImageManager();
			Graphics::Color Transparency();
			Graphics::Image* GetImage(const std::string& DirName, const std::string& FileName);
		private:
			Graphics::Canvas* _Canvas;
			Graphics::Color _Transparency;
			std::unordered_map<std::string, Graphics::Image*> images;
		};
	}
}

#endif