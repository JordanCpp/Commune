#ifndef _Fallout_Game_Location_h_
#define _Fallout_Game_Location_h_

#include <vector>
#include "ScriptCritter.h"

namespace Fallout
{
    namespace Game
    {
        class Location
        {
        public:
        private:
            std::vector<ScriptCritter*> _ScriptCritters;
        };
    }
}

#endif