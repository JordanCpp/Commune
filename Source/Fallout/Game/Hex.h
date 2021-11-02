#ifndef _Fallout_Game_Hex_h_
#define _Fallout_Game_Hex_h_

#include "../../Engine/Common/XmlReader.hpp"
#include "../Managers/SpriteManager.h"

namespace Fallout
{
    namespace Game
    {
        class Hex
        {
        public:
            Hex(Managers::SpriteManager* spriteManager, Arc::Common::XmlReader* xmlReader);
            void Draw(Arc::Graphics::Point pos);
        private:
            Formats::Sprite* _Body = nullptr;
        };
    }
}

#endif