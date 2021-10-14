#ifndef _Fallout_Game_Settings_h_
#define _Fallout_Game_Settings_h_

#include <string>
#include "../../Engine/Graphics/Point.h"

namespace Fallout
{
    namespace Game
    {
        class Settings
        {
        public:
            Settings(const std::string& Name);
            ~Settings();
            const std::string& Path();
            size_t Fps();
            Graphics::Point WindowSize();
        private:
            Graphics::Point size;
            size_t fps;
            std::string path;
        };
    }
}

#endif