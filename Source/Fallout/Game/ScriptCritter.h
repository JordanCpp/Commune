#ifndef _Fallout_Game_ScriptCritter_h_
#define _Fallout_Game_ScriptCritter_h_

#include "Script.h"
#include "Critter.h"

namespace Fallout
{
    namespace Game
    {
        class Critter;

        class ScriptCritter: public Script
        {
        public:
            void Init(Critter* critter);
            Critter* Self();
        private:
            Critter* _Critter;
        };
    }
}

#endif