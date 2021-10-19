#ifndef _Fallout_Game_Location_h_
#define _Fallout_Game_Location_h_

#include "../Managers/ObjectManager.h"

namespace Fallout
{
    namespace Game
    {
        class Location
        {
        public:
            Location(Managers::ObjectManager* objectManager);
        private:
            Managers::ObjectManager* _ObjectManager;
            std::array<Game::Tile*, Limits::MaxTiles> _Tiles;
        };
    }
}

#endif