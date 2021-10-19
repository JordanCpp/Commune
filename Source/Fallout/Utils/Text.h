#ifndef _Fallout_Utils_Text_h_
#define _Fallout_Utils_Text_h_

#include <string>

namespace Fallout
{
    namespace Utils
    {
        class Text
        {
        public:
            bool ContainsPercent(const std::string& value);
            int ParsePercent(const std::string& value);
            bool IsInt(const std::string& value);
        private:
        };
    }
}

#endif