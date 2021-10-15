#ifndef _Disciples_Game_Settings_h_
#define _Disciples_Game_Settings_h_

#include <string>
#include "../../Engine/Graphics/Point.h"

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
    private:
        Arc::Graphics::Point size;
        size_t fps;
        std::string path;
        std::string title;
    };
}

#endif