#ifndef _Fallout_Managers_ScriptManager_h_
#define _Fallout_Managers_ScriptManager_h_

#include <array>
#include "../Game/ScriptCritter.h"

namespace Fallout
{
    namespace Managers
    {
        class ScriptManager
        {
        public:
            enum
            {
                Max = 4096
            };
            ScriptManager();
            ~ScriptManager();
            Game::ScriptCritter* Critter(const std::string& file);
        private:
            std::array<Game::ScriptCritter*, Max> _Scripts;
        };
    }
}

#endif