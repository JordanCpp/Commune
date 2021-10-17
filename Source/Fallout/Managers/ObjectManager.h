#ifndef _Fallout_Managers_ObjectManager_h_
#define _Fallout_Managers_ObjectManager_h_

#include "../Game/Tile.h"
#include "../Game/Critter.h"
#include "ProtoManager.h"
#include "SpriteManager.h"
#include "ScriptManager.h"

namespace Fallout
{
    namespace Managers
    {
        class ObjectManager
        {
        public:
            ObjectManager(const std::string& path, SpriteManager* spriteManager);
            Game::Tile* Tile(const std::string& protoFile);
            Game::Critter* Critter(const std::string& protoFile, const std::string& scriptFile);
        private:
            ProtoManager _ProtoManager;
            ScriptManager _ScriptManager;
            SpriteManager* _SpriteManager;
        };
    }
}

#endif