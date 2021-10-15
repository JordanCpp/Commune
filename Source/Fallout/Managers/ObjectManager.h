#ifndef _Fallout_Managers_ObjectManager_h_
#define _Fallout_Managers_ObjectManager_h_

#include "../Game/Tile.h"
#include "../Game/Critter.h"
#include "ProtoManager.h"
#include "SpriteManager.h"

namespace Fallout
{
    namespace Managers
    {
        class ObjectManager
        {
        public:
            ObjectManager(const std::string& path, SpriteManager* spriteManager);
            Game::Tile* Tile(const std::string& file);
            Game::Critter* Critter(const std::string& proto, const std::string& script);
        private:
            ProtoManager _ProtoManager;
            SpriteManager* _SpriteManager;
        };
    }
}

#endif