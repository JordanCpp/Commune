#ifndef _Fallout_Managers_SpriteManager_h_
#define _Fallout_Managers_SpriteManager_h_

#include <unordered_map>
#include "../Formats/Sprite.h"
#include "../../Engine/Managers/ImageManager.h"

namespace Fallout
{
    namespace Managers
    {
        class SpriteManager
        {
        public:
            SpriteManager(const std::string& path, Arc::Graphics::Canvas* canvas, Arc::Graphics::Color transparency);
            ~SpriteManager();
            Formats::Sprite* Sprite(const std::string& dir, const std::string& file);
            Formats::Sprite* Tile(const std::string& file);
            Formats::Sprite* Critter(const std::string& file);
        private:
            Arc::Managers::ImageManager _ImageManager;
            std::unordered_map<std::string, Formats::Sprite*> _Sprites;
        };
    }
}

#endif