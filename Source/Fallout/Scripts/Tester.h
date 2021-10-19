#ifndef _Fallout_Scripts_Tester_h_
#define _Fallout_Scripts_Tester_h_

#include "../Game/ScriptCritter.h"

namespace Fallout
{
    namespace Game
    {
        class Tester: public ScriptCritter
        {
        public:
            void Talk(UI::Dialog* dialog, size_t node);
            void MapEnter();
        private:
        };
    }
}

#endif