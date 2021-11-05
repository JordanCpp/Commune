#ifndef _Arcturus_Managers_TextureManager_h_
#define _Arcturus_Managers_TextureManager_h_

#include <unordered_map>
#include "Manager.h"
#include "../Graphics/Texture2D.h"

namespace Arc
{
	namespace Managers
	{
		class TextureManager
		{
		public:
			TextureManager(const std::string& path);
			Graphics::Texture2D* GetTexture2D(const std::string& dir, const std::string& file);
		private:
			Manager _Manager;
			std::unordered_map<std::string, Graphics::Texture2D*> _Textures2D;
		};
	}
}

#endif