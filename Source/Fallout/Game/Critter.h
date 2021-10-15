#ifndef _Fallout_Game_Critter_h_
#define _Fallout_Game_Critter_h_

#include "ScriptCritter.h"

class ScriptCritter;

namespace Fallout
{
    namespace Game
    {
        class Critter
        {
        public:
            ScriptCritter* Self();
        private:
            ScriptCritter* _Script;
        };
    }
}

#endif