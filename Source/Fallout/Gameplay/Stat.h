#ifndef _Fallout_Gameplay_Stat_h_
#define _Fallout_Gameplay_Stat_h_

#include <array>
#include "StatValue.h"

namespace Fallout
{
    namespace Gameplay
    {
        class Stat
        {
        public:
            enum
            {
                Strength,
                Perception,
                Endurance,
                Charisma,
                Intelligence,
                Agility,
                Luck,
                Max
            };
            int Value(size_t index);
            int Number(size_t index);
            int Percent(size_t index);
            void Value(size_t index, int value);
            void Number(size_t index, int value);
            void Percent(size_t index, int value);
            int Get(size_t index);
        private:
            std::array<Gameplay::StatValue, Max> _Stats;
        };
    }
}

#endif