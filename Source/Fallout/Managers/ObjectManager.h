#ifndef _Fallout_Managers_ObjectManager_h_
#define _Fallout_Managers_ObjectManager_h_

#include "../Game/Tile.h"
#include "ProtoManager.h"

namespace Fallout
{
    namespace Managers
    {
        class ObjectManager
        {
        public:
            Game::Tile* Tile(const std::string& file);
        private:
            ProtoManager _ProtoManager;
        };
    }
}

#endif