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
            enum
            {
                RatioX = 16,
                RatioY = 12,
                Width = 5 * RatioX,
                Height = 3 * RatioY
            };

        public:
            Tile(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader);
        private:
            Formats::Sprite* _Body;
        };
    }
}

#endif