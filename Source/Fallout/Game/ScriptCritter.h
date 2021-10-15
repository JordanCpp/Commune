#ifndef _Fallout_Game_ScriptCritter_h_
#define _Fallout_Game_ScriptCritter_h_

#include "Script.h"
#include "Critter.h"

class Critter;

namespace Fallout
{
    namespace Game
    {
        class ScriptCritter: public Script
        {
        public:
            Critter* Self();
        private:
            Critter* _Critter;
        };
    }
}

#endif