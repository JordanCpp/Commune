#ifndef _Fallout_Gameplay_StatValue_h_
#define _Fallout_Gameplay_StatValue_h_

#include <cstdint>

namespace Fallout
{
    namespace Gameplay
    {
        class StatValue
        {
        public:
            StatValue();
            int Value();
            int Number();
            int Percent();
            void Value(int value);
            void Number(int value);
            void Percent(int value);
        private:
            int _Value;
            int _Number;
            int _Percent;
        };
    }
}

#endif