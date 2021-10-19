#ifndef _Fallout_Game_ScriptCritter_h_
#define _Fallout_Game_ScriptCritter_h_

#include "Script.h"
#include "Critter.h"
#include "../UI/Dialog.h"

namespace Fallout
{
    namespace Game
    {
        class Critter;
        class Dialog;

        class ScriptCritter: public Script
        {
        public:
            void Talk(Dialog* dialog, size_t node);
            void Init(Game::Critter* critter);
            Critter* Self();
        private:
            Critter* _Critter;
        };
    }
}

#endif