#ifndef _Fallout_Game_Critter_h_
#define _Fallout_Game_Critter_h_

#include "ScriptCritter.h"
#include "../../Engine/Common/XmlReader.hpp"
#include "../Managers/ProtoManager.h"
#include "../Gameplay/Stat.h"

namespace Fallout
{
    namespace Game
    {
        class ScriptCritter;

        class Critter
        {
        public:
            Critter(const std::string& protoFile, Managers::ProtoManager* protoManager);
            void ReadParent(Arc::Common::XmlReader* reader);
            void ReadStat(Arc::Common::XmlReader* reader, size_t stat, const std::string& name);
            void Init(ScriptCritter* script);
            ScriptCritter* Self();
            Gameplay::Stat& Stat();
        private:
            ScriptCritter* _Script;
            Gameplay::Stat _Stat;
        };
    }
}

#endif