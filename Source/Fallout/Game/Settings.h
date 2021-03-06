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
            Arc::Graphics::Point WindowSize();
            const std::string& Title();
            size_t SystemSize();
            size_t GeneralSize();
        private:
            Arc::Graphics::Point size;
            size_t fps;
            std::string path;
            std::string title;
            size_t _SystemSize;
            size_t _GeneralSize;
        };
    }
}

#endif