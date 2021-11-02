#ifndef _Fallout_Game_Tile_h_
#define _Fallout_Game_Tile_h_

#include "../../Engine/Common/XmlReader.hpp"
#include "../Managers/SpriteManager.h"

namespace Fallout
{
    namespace Game
    {
        class Tile
        {
        public:
            enum
            {
                RatioX = 16,
                RatioY = 12,
                Width = 5 * RatioX,
                Height = 3 * RatioY
            };

            Tile(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader);
            void Draw(Arc::Graphics::Point pos);
        private:
            Formats::Sprite* _Body = nullptr;
        };
    }
}

#endif