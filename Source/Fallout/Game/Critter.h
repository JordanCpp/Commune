#ifndef _Fallout_Game_Critter_h_
#define _Fallout_Game_Critter_h_

#include "ScriptCritter.h"
#include "../../Engine/Common/XmlReader.hpp"

class ScriptCritter;

namespace Fallout
{
    namespace Game
    {
        class Critter
        {
        public:
            Critter(Arc::Common::XmlReader* xmlReader);
            void Init(ScriptCritter* script);
            ScriptCritter* Self();
        private:
            ScriptCritter* _Script;
        };
    }
}

#endif