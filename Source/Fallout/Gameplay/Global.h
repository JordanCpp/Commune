#ifndef _Fallout_Gameplay_Global_h_
#define _Fallout_Gameplay_Global_h_

#include <unordered_map>

namespace Fallout
{
    namespace Gameplay
    {
        class Global
        {
        public:
            int Get(const std::string& name);
        private:
            std::unordered_map<std::string, int> _Vars;
        };
    }
}

#endif