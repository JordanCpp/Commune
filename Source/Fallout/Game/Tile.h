#ifndef _Fallout_Game_Tile_h_
#define _Fallout_Game_Tile_h_

#include "../../Engine/Common/XmlReader.hpp"

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
            Tile(Arc::Common::XmlReader* reader);
        private:
        };
    }
}

#endif